#include <string>
#include <vector>

using namespace std;
long long dp[5001];
int solution(int n) {
      int answer = 0;
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    for(int i=3;i<=n;i++){
        if(i%2==1)
            continue;
        dp[i] = 3*dp[i-2];
        for(int j = i-4;j>=0;j-=2){
            dp[i]+=(2*dp[j]);
        }
        dp[i]%=1000000007;
    }
    answer = dp[n];
    return answer;
}
