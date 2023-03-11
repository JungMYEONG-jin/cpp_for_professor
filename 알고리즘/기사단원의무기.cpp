#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getDivs(int number){
    int cnt = 0;
    for(int i=1;i<=sqrt(number);i++){
        if(number%i==0){
            if(i!=number/i)
                cnt+=2;
            else
                cnt+=1;
        }
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> res;
    for(int i=1;i<=number;i++){
        res.push_back(getDivs(i));
    }
    for(int num : res){
        if(num>limit)
            answer+=power;
        else
            answer+=num;
    }
    return answer;
}
