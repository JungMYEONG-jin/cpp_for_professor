#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <map>
#include <set>

#define INF 999999999

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    sort(X.begin(), X.end(),[](auto it, auto it2){return it>it2;});
    sort(Y.begin(), Y.end(),[](auto it, auto it2){return it>it2;});

    int len1 = X.length();
    int len2 = Y.length();
    string left = X;
    string right = Y;
    if(len1>len2){
        left = Y;
        right = X;
    }
    bool selected[10] = {false,};
    for(int i=0, len = left.length();i<len;i++){
        int num = left[i] - '0';
        if(!selected[num]){
            selected[num] = true;
            int rightCnt = count(right.begin(), right.end(), left[i]);
    
            if(rightCnt>0){
                int leftCnt = count(left.begin(), left.end(), left[i]);
                answer += string(min(leftCnt, rightCnt), left[i]);
            }
        }
    }

    if (answer.empty())
    {
        /* code */
        return "-1";
    }
    answer.erase(0, min(answer.find_first_not_of('0'), answer.size()-1));
    return answer;
}
