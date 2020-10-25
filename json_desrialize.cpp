#include "json.hpp"
#include <string>
#include <string_view>
#include <iostream>
#include "movies.h"
#include <ostream>
#include <fstream>
using namespace std;

using json = nlohmann::json;

movie_list desrialize_json(string_view filepath)
{
	ifstream i(filepath.data());
	movie_list movies;
	if (i.is_open())
	{
		json j;

		try
		{
			i >> j;

			if (j.is_object())
			{
				for (auto& ele : j.at("movies"))
				{
					movie m;
					m.id = ele.at("id").get<unsigned int>();
					m.title = ele.at("title").get<string>();
					m.year = ele.at("year").get<unsigned int>();
					m.length = ele.at("length").get<unsigned int>();

					for (auto& role : ele.at("cast"))
					{
						m.cast.push_back(casting_role{ role.at("star").get<string>(), role.at("name").get<string>() });
					}

					for (auto& direc : ele.at("directors"))
					{
						m.directors.push_back(direc);
					}
					for (auto& writer : ele.at("writers"))
					{
						m.writers.push_back(writer);
					}
					movies.push_back(move(m));
				}
			}
		}
		catch (exception const& ex)
		{
			cout << ex.what() << endl;
		}

	}

	return movies;

}

int main()
{
	auto movies = desrialize_json("test.json");

	cout << movies[0].title << " " << movies[0].id << endl;

}