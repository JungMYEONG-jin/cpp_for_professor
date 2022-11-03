#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    //  어쨌든 짝수니까 물은 가운데만 넣으면 됨
    string left = "";
    for(int i=1,len=food.size();i<len;i++){
        left+=string(food[i]/2, i+'0');
    }
    answer+=left;
    answer+="0";
    reverse(left.begin(), left.end());
    answer+=left;
    return answer;
}
