#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    for(char ch : s){
        
        int idx = ch - 'a';
        int temp = index;
        int cnt = index;
        for(int i = 1;i<=temp;i++){
            if(skip.find(alpha[(idx+i)%26]) != skip.npos){
                temp++;
                cnt++;
            } 
        }
        idx+=cnt;
        answer += (alpha[idx%26]);
    }
    
    return answer;
}
