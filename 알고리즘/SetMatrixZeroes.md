```c++
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
    int col = matrix[0].size();
    queue<pair<int, int>> q;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]==0)
            {
                for(int k=i;k<row;k++){
                    q.push({k, j});
                }
                for(int k=i;k>=0;k--){
                    q.push({k, j});
                }
                for(int k=j;k<col;k++){
                    q.push({i, k});
                }
                for(int k=j;k>=0;k--){
                    q.push({i, k});
                }
            }
               
        }
    }

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        matrix[it.first][it.second] = 0;
    }
        
    }
};
```
