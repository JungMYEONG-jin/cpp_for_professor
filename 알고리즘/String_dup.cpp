#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <array>
#include <functional>
#include <random>
#include <chrono>
#include <thread>
#include <future>

using namespace std;


std::vector<std::string> dup(std::vector<std::string> arr) {
    //..

    for (auto& i : arr)
        i.erase(unique(i.begin(), i.end()), i.end());

    
    return arr;

}

std::vector<std::string> uniq(const std::vector<std::string>& v) {
   
    vector<string> k = v;

    k.erase(unique(k.begin(), k.end()), k.end());
    
    
    
    return k;
}

int main()
{
    {
        
        
        auto k = dup(vector<string>{"ccooddddddewwwaaaaarrrrsssss", "piccaninny", "hubbubbubboo"});

        for (auto& i : k)
            cout << i << endl;
            //Equals(vector<string>{"codewars", "picaniny", "hubububo"}));


    }

    {


        auto k = dup(vector<string>{"abracadabra", "allottee", "assessee"});

        for (auto& i : k)
            cout << i << endl;
        // "abracadabra", "alote", "asese"}


    }

    {


        auto k = dup(vector<string>{"kelless", "keenness"});

        for (auto& i : k)
            cout << i << endl;
        // "keles", "kenes"


    }
   
   
}