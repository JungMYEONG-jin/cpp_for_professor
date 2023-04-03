#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int ex = park.size();
    int ey = park[0].size();
    int sx, sy;
    bool isFind = false;
    for(int i=0, len = park.size();i<len;i++){
        for(int j=0, slen = park[i].size();j<slen;j++){
            if(park[i][j]=='S'){
                sx = i;
                sy = j;
                isFind = true;
                break;
            }
        }
        if(isFind)
            break;
    }

    for(const auto& it : routes){
        char dir = it[0];
        int n = it[2] - '0';
        if(dir=='E'){
            if(n+sy>=ey)
                continue;
            else{
                bool counted = false;
                for(int i=sy;i<=sy+n;i++){
                    if(park[sx][i]=='X')
                    {
                        counted = true;
                        break;
                    }
                }
                if(!counted)
                    sy+=n;
            }
        }else if(dir=='S'){
            if(n+sx>=ex)
                continue;
            else{
                bool counted = false;
                for(int i=sx;i<=sx+n;i++){
                    if(park[i][sy]=='X')
                    {
                        counted = true;
                        break;
                    }
                }
                if(!counted)
                    sx+=n;
        }
        }else if(dir=='W'){
            if(sy-n<0)
                continue;
            else{
                bool counted = false;
                for(int i=sy;i>=sy-n;i--){
                    if(park[sx][i]=='X')
                    {
                        counted = true;
                        break;
                    }
                }
                if(!counted)
                    sy-=n;
        }
        }else if(dir=='N'){
            if(sx-n<0)
                continue;
            else{
                bool counted = false;
                for(int i=sx;i>=sx-n;i--){
                    if(park[i][sy]=='X')
                    {
                        counted = true;
                        break;
                    }
                }
                if(!counted)
                    sx-=n;
            }
        }
    }
    answer.push_back(sx);
    answer.push_back(sy);
    return answer;
}
