#include <string>
#include <string_view>
#include <iostream>
#include <regex>
#include <assert.h>
#include <optional>

using namespace std;

struct uri_parts
{
	string protocol; // url must include protocol and domain 
	string domain;
	optional<int> port;
	optional<string> path;
	optional<string> query;
	optional<string> fragment;
};

optional<uri_parts> get_url_structure(string url)
{
	auto match = smatch{};
	
	regex re{ R"(^(\w+):\/\/([\w.-]+)(:(\d+))?([\w\/\.]+)?(\?([\w=&]*)(#?(\w+))?)?$)" };

	if (regex_match(url, match, re))
	{
		if (match[1].matched && match[2].matched)
		{
			uri_parts res;
			res.protocol = match[1].str();
			res.domain = match[2].str();

			if (match[4].matched)
				res.port = stoi(match[4]);
			if (match[5].matched)
				res.path = match[5];
			if (match[7].matched)
				res.query = match[7];
			if (match[9].matched)
				res.fragment = match[9];


			return res;
		}


	}
	return {};

}




int main()
{
	auto p1 = get_url_structure("https://packt.com");
	cout << p1->domain << endl;
	cout << p1->port.has_value() << endl;
	assert(p1);
	assert(p1->protocol == "https");
	assert(p1->domain == "packt.com");
	assert(!p1->port);
	assert(!p1->path);
	assert(!p1->query);
	assert(!p1->fragment);
	// all success

	auto p2 = get_url_structure("https://bbc.com:80/en/index.html?lite=true#ui");
	assert(p2);
	assert(p2->protocol == "https");
	assert(p2->domain == "bbc.com");
	assert(p2->port == 80);
	cout << p2->path.value() << endl;
	assert(p2->path.value() == "/en/index.html");
	assert(p2->query.value() == "lite=true");
	assert(p2->fragment.value() == "ui");
}