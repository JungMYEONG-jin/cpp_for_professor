#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <regex>

#include "../ZipLib/ZipArchive.h"
#include "../ZipLib/ZipFile.h"

#ifdef USE_BOOST_FILESYSTEM
#  include <boost/filesystem/path.hpp>
#  include <boost/filesystem/operations.hpp>
namespace fs = boost::filesystem;
#else
#  include <filesystem>
#  ifdef FILESYSTEM_EXPERIMENTAL
namespace fs = std::experimental::filesystem;
#  else
namespace fs = std::filesystem;
#  endif
#endif
using namespace std;


vector<string> archive_find(fs::path const& archivepath, string_view pattern)
{

vector<string> res;

if(fs::exists(archivepath))
{
try
{
auto archive = ZipFile::Open(archivepath.string());

for(size_t i = 0 ;i<archive->GetEntriesCount();i++)
{
auto entry = archive->GetEntry(i);
if(entry)
{
if(!entry->isDirecotry())
{

auto name = entry->GetName();
if(regex_match(name, regex{pattern.data()})
{
res.push_back(entry->GetFullName());
}
}
}
}
}catch(exception const& ex)
{
cout<<ex.what()<<endl;
}
}
return res;
}

int main()
{

auto res = archive_find("sample.zip", R"(^.*\.jpg$)"); // jpg로 끝나는 파일들

for(auto name : res)
{
cout<<name<<endl;
}


}



