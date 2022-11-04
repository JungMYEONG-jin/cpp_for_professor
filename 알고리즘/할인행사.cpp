
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
#include <string>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> db;
    for (int i = 0, len = want.size(); i < len; i++) {
        db[want[i]] = number[i];
    }

    for (int i = 0, len = discount.size(); i < len - 9; i++) {
        map<string, int> temp = db;
        bool exact = true;
        for (int j = i; j < i + 10; j++) {
            if(temp.find(discount[j])!=temp.end())
            {
                temp[discount[j]]--;
                if(temp[discount[j]]<0)
                {
                    exact = false;
                    break;
                }

            }
        }

        if(!exact)
            continue;

        int acc = accumulate(temp.begin(), temp.end(), 0, [](int value, const map<string, int>::value_type& it) {
            return value + it.second; });
        if (acc == 0)
            answer++;
    }
    return answer;
}
