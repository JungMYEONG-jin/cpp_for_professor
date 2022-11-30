#include <iostream>
#include <numeric>
#include <string>
#include <filesystem>
#include <chrono>

using namespace std;

namespace ch = std::chrono;

namespace fs = std::filesystem;



template<typename Duration>
bool is_older(fs::path const& p1, Duration const duration)
{

	auto lastwrite = fs::last_write_time(p1);

	auto lastdur = lastwrite.time_since_epoch();
	auto current = (ch::system_clock::now() - duration).time_since_epoch();

	return ch::duration_cast<Duration>(current - lastdur).count() > 0;


}

template<typename Duration>
void delete_directory(fs::path const& p1, Duration const duration)
{

	try
	{
		if (fs::exists(p1))
		{
			if (is_older(p1, duration))
			{
				fs::remove(p1);
			}
			else if (fs::is_directory(p1))
			{
				for (auto const& entry : fs::directory_iterator(p1))
					delete_directory(entry.path(), duration);
			}
		}
	}
	catch (exception const& ex)
	{
		cerr << ex.what() << endl;
	}




}

int main()
{
	using namespace std::chrono_literals;

#ifdef _WIN32
	auto path = R"(..\Test\)";
#else
	auto path = R"(../Test/)";
#endif

	delete_directory(path, 1h + 20min);
}