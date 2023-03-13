```c++
#include <set>

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        unordered_set<int> rows;
        unordered_set<int> cols;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }

        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(rows.count(i)>0 || cols.count(j)>0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

```
