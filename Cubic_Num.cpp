#include <string>
#include <vector>
#include <regex>
#include <algorithm>

class Cubes
{
public:
  static std::string isSumOfCubes(std::string &str);
};

std::string Cubes::isSumOfCubes(std::string &str)
{
    std::vector<std::string> cubics = {"0", "00", "000", "1", "01", "001", "153", "370", "371", "407"};
    std::vector<std::string> nb = {};
    std::regex exp("\\d{1,3}");
    std::smatch res;
    std::string::const_iterator searchStart(str.cbegin());
    while (regex_search(searchStart, str.cend(), res, exp))
    {
        std::string r = res[0];
        nb.push_back(r);
        searchStart += res.position() + res.length();
    }
    int sum = 0; std::string result = "";
    for (unsigned int i = 0; i < nb.size(); i++)
    {
        std::string k = nb[i];
        if (std::find(cubics.begin(), cubics.end(), k) != cubics.end())
        {
            result += std::to_string(std::stoi(k)) + " ";
            sum += std::stoi(k);
        }
    }
    if (result == "")
        return "Unlucky";
    return result + std::to_string(sum) + " Lucky";
}
