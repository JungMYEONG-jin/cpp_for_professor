#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    long long take = 0;
    long long remove = 0;
    
    for(int i=n-1;i>=0;i--){
        int cnt = 0;
        while(take<deliveries[i] || remove<pickups[i]){
            ++cnt;
            take+=cap;
            remove+=cap;
        }
        take -= deliveries[i];
        remove -= pickups[i];
        long long res = (i+1) * cnt * 2;
        answer += res;
    }
    
    
    return answer;
}
