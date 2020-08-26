#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>


using namespace std;

// Best Clver Method
class DirReductions
{
public:
    static std::vector<std::string> dirReduc(const std::vector<std::string>& arr);
    static const std::unordered_map<std::string, std::string> oppositeWays;
};

const std::unordered_map<std::string, std::string> DirReductions::oppositeWays{
    {"EAST", "WEST"},
    {"WEST", "EAST"},
    {"NORTH", "SOUTH"},
    {"SOUTH", "NORTH"},
};


std::vector<std::string> DirReductions::dirReduc(const std::vector<std::string>& arr) {
   

    vector<string> res;

    for (const auto& way : arr)
    {
        if (res.empty() || res.back() != oppositeWays.at(way))
        {
            res.push_back(way);
        }
        else
        {
            res.pop_back();
        }
    }


    return res;



}



// MyCode

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string>& arr)
    {
        if (arr.size() <= 1)
            return arr;


        map<string, string> direction;

        direction["NORTH"] = "SOUTH";
        direction["SOUTH"] = "NORTH";
        direction["EAST"] = "WEST";
        direction["WEST"] = "EAST";
       


        for (int i = 0; i < arr.size() - 1; )
        {
            if (arr.size() > 1 && direction[arr[i]] == arr[i + 1])
            {
                arr.erase(arr.begin() + i, arr.begin() + i + 2);
                i = 0;
            }
            else
                i++;
        }

        return arr;
    }


};

int main()
{
    std::vector<std::string> d1 = { "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" };
    std::vector<std::string> d2 = { "NORTH", "EAST", "SOUTH", "WEST" };

    auto k = DirReduction::dirReduc(d1);

    for (auto& i : k)
        cout << i << " ";
    cout << endl;
    auto p = DirReduction::dirReduc(d2);
    for (auto& i : p)
        cout << i << " ";

}