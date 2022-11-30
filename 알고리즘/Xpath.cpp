#include <string>
#include <string_view>
#include <assert.h>
#include "pugixml.hpp"
#include <iostream>
using namespace std;

int main()
{

	string text = R"(
<?xml version="1.0"?>
<movies>
	<movie id="11001" title="The Matrix" year="1999" length="196">
		<cast>
			<role star="Keanu Reeves" name="Neo" />
			<role star="Laurence Fishburne" name="Morpheus" />
			<role star="Carrie-Anne Moss" name="Trinity" />
			<role star="Hugo Weaving" name="Agent Smith" />
		</cast>
		<directors>
			<director name="Lana Wachowski" />
			<director name="Lilly Wachowski" />
		</directors>
		<writers>
			<writer name="Lana Wachowski" />
			<writer name="Lilly Wachowski" />
		</writers>
	</movie>
	<movie id="9871" title="Forrest Gump" year="1994" length="202">
		<cast>
			<role star="Tom Hanks" name="Forrest Gump" />
			<role star="Sally Field" name="Mrs. Gump" />
			<role star="Robin Wright" name="Jenny Curran" />
			<role star="Mykelti Williamson" name="Bubba Blue" />
		</cast>
		<directors>
			<director name="Robert Zemeckis" />
		</directors>
		<writers>
			<writer name="Winston Groom" />
			<writer name="Eric Roth" />
		</writers>
	</movie>
</movies>
)";

	pugi::xml_document doc;
	if (doc.load_string(text.c_str()))
	{
		try
		{
			auto title = doc.select_nodes("/movies/movie[@length>200]");

			for (auto it : title)
			{
				cout << it.node().attribute("title").as_string() << endl;
			}
		}
		catch(pugi::xpath_exception const& e)
		{
			cout << e.result().description() << endl;
		}

		try {
			auto title = doc.select_nodes("/movies/movie/cast/role[last()]");

			for (auto it : title)
			{
				cout << it.node().attribute("star").as_string() << endl;
			}
		}
		catch (pugi::xpath_exception const& e)
		{
			cout << e.result().description() << endl;
		}
	}






}