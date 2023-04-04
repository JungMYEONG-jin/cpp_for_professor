#include <string>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

int table[3][3] = {{1,1,1}, {5, 1, 1}, {25, 5, 1}};

int dfs(vector<int>& picks, const vector<int>& vec, int cnt, int depth){
    if(depth >= vec.size() || (picks[0] == 0 && picks[1] == 0 && picks[2] == 0))
    {
        return cnt;
    }
    
    int minCnt = 9999999;
    int temp, idx;
    
    for(int i=0;i<3;i++){
        if(picks[i]){
            picks[i]--;
            temp = 0;
            idx = depth;
            while(idx<depth+5 && idx<vec.size())
                temp+=table[i][vec[idx++]];
            minCnt = min(minCnt, dfs(picks, vec, cnt + temp, idx));
            picks[i]++;
        }
    }
    return minCnt;
}


int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    vector<int> vec;
    for(const auto& it : minerals){
        if(it=="diamond")
            vec.push_back(0);
        else if(it=="iron")
            vec.push_back(1);
        else if(it=="stone")
            vec.push_back(2);
    }
    answer = dfs(picks, vec, 0, 0);
    return answer;
}
