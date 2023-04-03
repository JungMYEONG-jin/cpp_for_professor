#include <string>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

int ans = 99999999;

void dfs(vector<int>& picks, vector<tuple<int, int, int>> vec, int cnt, int sum){
    if(vec.size() == cnt)
    {
        ans = min(ans, sum);
        return;
    }

    if(sum > ans)
        return;

    for(int i=0;i<3;i++){
        for(int j=0;j<picks[i];j++){
            picks[i]--;
            if(i==0)
                dfs(picks, vec, cnt+1, sum + get<0>(vec[cnt]));
            else if(i==1)
                dfs(picks, vec, cnt+1, sum + get<1>(vec[cnt]));
            else if(i==2)
                dfs(picks, vec, cnt+1, sum + get<2>(vec[cnt]));
            picks[i]++;
        }
    }
}


int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;

    int mine[3][3] = {{1, 5, 25}, {1, 1, 5}, {1, 1, 1}};
    map<string, int> db = {{"diamond", 0}, {"iron", 1}, {"stone", 2}};

    int len = minerals.size();
    int remain = min(5*(picks[0] + picks[1] + picks[2]), len);

    int dia = 0, iron = 0, stone = 0, cnt = 0;
    vector<tuple<int, int, int>> vec;
    for(int i=0;i<remain;i++){
        dia += mine[db[minerals[i]]][0];
        iron += mine[db[minerals[i]]][1];
        stone += mine[db[minerals[i]]][2];
        if(++cnt<5 && i != len-1)
            continue;
        vec.push_back({dia, iron, stone});
        dia = 0;
        iron = 0;
        stone = 0;
        cnt = 0;
    }

    dfs(picks, vec, 0, 0);
    return answer = ans;
}
