#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int l1 = cards1.size();
    int l2 = cards2.size();
    int idx1 = 0;
    int idx2 = 0;
    int gidx = 0;
    int len = goal.size();
    while(gidx<len){
        if(idx1<l1 && cards1[idx1] == goal[gidx]){
            idx1++;
        }else if(idx2<l2 && cards2[idx2] == goal[gidx]){
            idx2++;
        }else{
            return "No";
        }
        gidx++;
    }
    answer = "Yes";
    return answer;
}
