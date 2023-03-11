#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    vector<long> res;
    int len = t.size();
    int plen = p.size();
    for(int i=0;i<len;i++){
        if(i+plen<=len){
            long k = stol(t.substr(i, plen));
            cout<<k<<endl;
            res.push_back(k);
        }  
    }
    long val = stol(p);
    answer = count_if(res.begin(), res.end(), [val](auto it){
        return it<=val;
    });
    return answer;
}
