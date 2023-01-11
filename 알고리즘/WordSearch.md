## 백트래킹

모든 경우의수에 대해 재귀를 시도하자

```c++
class Solution {
public:
    // search 4 direction
    bool search(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, string word, int len){
        if(board[x][y]!=word[len])
            return false;
        if(word.length() == len+1)
            return true;
        visited[x][y] = true;
        bool up = x<=0||visited[x-1][y] ? false : search(board, visited, x-1, y, word, len+1);
        bool down = x>=board.size()-1 || visited[x+1][y] ? false : search(board, visited, x+1, y, word, len+1);
        bool left = y<=0 || visited[x][y-1] ? false : search(board, visited, x, y-1, word, len+1);
        bool right = y>=board[0].size()-1 || visited[x][y+1] ? false : search(board, visited, x, y+1, word, len+1);
        visited[x][y] = false;
        
        return up || down ||left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col));
        
        for(int x = 0; x<row; x++){
            for(int y = 0; y<col; y++){
                if(search(board, visited, x, y, word, 0))
                    return true;
            }
        }
        return false;
    }
};
```
