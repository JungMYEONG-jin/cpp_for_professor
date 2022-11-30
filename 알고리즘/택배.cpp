#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> res;
    res.push(1000001);
    for(int i=1, len=order.size();i<=len;i++){
        if(order[answer]==i){
            answer++;
        }else if(order[answer]==res.top()){
            res.pop();
            answer++;
            i-=1; // 지금꺼 다시 -해야 다음에 지금라인 넣음
        }else{
            res.push(i);
        }
    }
    while(res.size()!=1){
        if(order[answer]==res.top()){
            answer++;
            res.pop();
        }else
            break;
    }
    
    return answer;
}
