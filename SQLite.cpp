#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#include "sqlite_modern_cpp.h"
#include "sqlite3.h"
#include "movies.h"

std::vector<std::string> split(std::string text, char const delimiter)
{
	auto sstr = std::stringstream{ text };
	auto tokens = std::vector<std::string>{};
	auto token = std::string{};
	while (std::getline(sstr, token, delimiter))
	{
		if (!token.empty()) tokens.push_back(token);
	}
	return tokens;
}
movie read_movie()
{
	movie m;
	cout << "Enter Movie" << endl;
	cout << "Title: ";
	getline(cin, m.title);
	cout << "Year: ";
	cin >> m.year;
	cout << "Length: ";
	cin >> m.length;
	cin.ignore();
	string directors;
	cout << "Directors: ";
	getline(cin, directors);
	m.directors = split(directors, ',');
	string writers;
	cout << "Writers: ";
	getline(cin, writers);
	m.writers = split(writers, ',');
	string cast;
	cout << "Cast: ";
	getline(cin, cast);
	auto roles = split(cast, ',');
	for (auto const& r : roles)
	{
		auto pos = r.find_first_of('=');
		casting_role cr;
		cr.actor = r.substr(0, pos);
		cr.role = r.substr(pos + 1, r.size() - pos - 1);
		m.cast.push_back(cr);
	}
	return m;

}

sqlite_int64 get_person_id(string const& name, sqlite::database& db)
{
	sqlite_int64 id = 0;
	db << "select rowid from persons where name=?;" << name >> [&id](sqlite_int64 const rowid) {id = rowid; };

	return id;
}

sqlite_int64 insert_persons(string_view name, sqlite::database& db)
{
	db << "insert into persons values(?);" << name.data();
	return db.last_insert_rowid(); // 최근 변경된 row id return
}

void insert_directors(sqlite_int64 const movie_id, vector<string> const& directors, sqlite::database& db)
{
	for (auto const& director : directors)
	{
		auto id = get_person_id(director, db);

		if (id == 0)
			id = insert_persons(director, db);

		db << "insert into directors values(?, ?);" << movie_id << id;
	}

}

void insert_writers(sqlite_int64 const& movie_id, vector<string> const& writers, sqlite::database& db)
{
	for (auto const& writer : writers)
	{
		auto id = get_person_id(writer, db);
		if (id == 0)
			id = insert_persons(writer, db);

		db << "insert into writers values(?, ?);" << movie_id << id;
	}
}


void insert_cast(sqlite_int64 const movie_id, vector<casting_role> const& cast, sqlite::database& db)
{
	for (auto const& cr : cast)
	{
		auto id = get_person_id(cr.actor, db);

		if (id == 0)
			id = insert_persons(cr.actor, db);

		db << "insert into casting values(?,?, ?);" << movie_id << id << cr.role;
	}
}

void insert_movie(movie& m, sqlite::database& db)
{
	try {
		db << "begin;";

		db << "insert into movies values(?,?,?);" << m.title << m.year << m.length;

		auto movieid = db.last_insert_rowid();

		insert_directors(movieid, m.directors, db);
		insert_writers(movieid, m.writers, db);
		insert_cast(movieid, m.cast, db);

		m.id = static_cast<unsigned int>(movieid);

		db << "commit;"; // 자료넣고 commit
	}
	catch (exception const&)
	{
		db << "rollback;";
		//error 발생시 롤백
	}
}
void print_movie(movie const& m)
{
	std::cout << "[" << m.id << "] "
		<< m.title << " (" << m.year << ") "
		<< m.length << "min" << std::endl;
	std::cout << " directed by: ";
	for (auto const& d : m.directors) std::cout << d << ",";
	std::cout << std::endl;
	std::cout << " written by: ";
	for (auto const& w : m.writers) std::cout << w << ",";
	std::cout << std::endl;
	std::cout << " cast: ";
	for (auto const& r : m.cast) std::cout << r.actor << " (" << r.role << "),";
	std::cout << std::endl << std::endl;
}
std::vector<std::string> get_directors(sqlite3_int64 const movie_id,
	sqlite::database& db)
{
	std::vector<std::string> result;
	db << R"(select p.name from directors as d 
            join persons as p on d.personid = p.rowid 
            where d.movieid = ?;)"
		<< movie_id
		>> [&result](std::string const name)
	{
		result.emplace_back(name);
	};

	return result;
}

std::vector<std::string> get_writers(sqlite3_int64 const movie_id,
	sqlite::database& db)
{
	std::vector<std::string> result;
	db << R"(select p.name from writers as w
         join persons as p on w.personid = p.rowid 
         where w.movieid = ?;)"
		<< movie_id
		>> [&result](std::string const name)
	{
		result.emplace_back(name);
	};

	return result;
}

std::vector<casting_role> get_cast(sqlite3_int64 const movie_id,
	sqlite::database& db)
{
	std::vector<casting_role> result;
	db << R"(select p.name, c.role from casting as c
         join persons as p on c.personid = p.rowid
         where c.movieid = ?;)"
		<< movie_id
		>> [&result](std::string const name, std::string role)
	{
		result.emplace_back(casting_role{ name, role });
	};

	return result;
}

movie_list get_movies(sqlite::database& db)
{
	movie_list movies;

	db << R"(select rowid, * from movies;)"
		>> [&movies, &db](sqlite3_int64 const rowid, std::string const& title,
			int const year, int const length)
	{
		movies.emplace_back(movie{
		   static_cast<unsigned int>(rowid),
		   title,
		   year,
		   static_cast<unsigned int>(length),
		   get_cast(rowid, db),
		   get_directors(rowid, db),
		   get_directors(rowid, db)
			});
	};

	return movies;
}
int main()
{
	try
	{
		sqlite::database db(R"(cppchallenger86.db)");

		auto movie = read_movie();
		insert_movie(movie, db);

		auto movies = get_movies(db);
		for (auto const& m : movies)
			print_movie(m);
	}
	catch (sqlite::sqlite_exception const& e)
	{
		std::cerr << e.get_code() << ": " << e.what() << " during "
			<< e.get_sql() << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
