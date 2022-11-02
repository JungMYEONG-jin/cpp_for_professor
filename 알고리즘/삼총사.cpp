#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>

#define INF 999999999

using namespace std;

// 3수 더해서 dfs
bool selected[13];
int temp = 0;
void dfs(vector<int>& number, int idx, int cnt){
    if (cnt==3)
    {
        /* code */
        int num = 0;
        for(int i=0, len=number.size();i<len;i++){
            if (selected[i])
            {
                /* code */
                num+=number[i];
            }
            
        }
        if (num==0)
        {

            temp++;
        }
        return;
        
    }
    
    for(int i=idx, len=number.size();i<len;i++){
        if (selected[i])
        {
            /* code */
            continue;
        }
        selected[i] = true;
        dfs(number, i, cnt+1);
        selected[i] = false;
        
    }  
}


int solution(vector<int> number) {
    int answer = 0;
    if (number.size()<3)
    {
        /* code */
        return 0;
    }
    dfs(number, 0, 0);
    answer = temp;
    return answer;
}
