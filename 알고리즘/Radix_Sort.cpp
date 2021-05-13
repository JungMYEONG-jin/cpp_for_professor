#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <sstream>
#include <cmath>
#include <map>

using namespace std;
  
  
  int main()
  {
  // key  indexed sorting

    vector<pair<string, int>> r;
    r.push_back({ "Anderson", 2 });
    r.push_back({ "Brown", 3 });
    r.push_back({ "Davies", 3 });
    r.push_back({ "Garcia", 4 });
    r.push_back({ "Harris", 1 });
    r.push_back({ "Jackson", 3 });
    r.push_back({ "Jonhson", 4 });
    r.push_back({ "Jones", 3 });
    r.push_back({ "Martin", 1 });
    r.push_back({ "Martinez", 2 });
    r.push_back({ "Miller", 2 });
    r.push_back({ "Moore", 1 });
    r.push_back({ "Robinson", 2 });
    r.push_back({ "Smith", 4 });
    r.push_back({ "Taylor", 3 });
    r.push_back({ "Thomas", 4 });
    r.push_back({ "Thompson", 4 });
    r.push_back({ "White", 2 });
    r.push_back({ "Wilson", 4 });
    r.push_back({ "Williamson", 3 });

    int len = r.size();
    int val = max_element(r.begin(), r.end(), [](auto e, auto k) {return e.second < k.second; })->second;
    vector<int> cnt(val+2); // 최대 section의 값
    cout<<"Key Indexed Sorting Start\n";
    for (auto i : r)
        cnt[i.second+1]++;
    
    for (int i = 0; i < val; i++) // frequency accumulate
        cnt[i + 1] += cnt[i];

    vector<string> aux(len);


    for (int i = 0; i < len; i++)
        aux[cnt[r[i].second]++] = r[i].first;

    vector<string> result(len);

    for (int i = 0; i < len; i++)
        result[i] = aux[i];

    for (auto i : result)
        cout << i << "\n";



}
