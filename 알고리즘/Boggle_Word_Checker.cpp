using namespace std;

 bool check_match(int prevX, int prevY, int current, vector<vector<bool>>& visited, const vector<vector<char>>& board, const string& word)
    {

        if (current >= word.size())
            return true;

        char cur_char = word[current];
        visited[prevY][prevX] = true;
        int len = board.size();
        int len2 = board[0].size();
        for (int y = prevY - 1; y <= prevY + 1; y++)
        {
            for (int x = prevX - 1; x <= prevX + 1; x++)
            {
                if (y >= 0 && x >= 0 && y < len && x < len2)
                {
                    if (board[y][x] == cur_char && !visited[y][x] && check_match(x, y, current + 1, visited, board, word))
                        return true;
                }
            }
        }
        cout<<current<<endl;
        visited[prevY][prevX] = false;
        return false;

    }

    bool check_word(const vector<vector<char> >& board, const string& word)
    {
        if (word.empty())
            return false;
        int len = board.size();
        int len2 = board[0].size();
        vector<vector<bool>> visited(len, vector<bool>(len2));

        for (int y = 0; y < len; y++)
        {
            for (int x = 0; x < len2; x++)
            {
                if (board[y][x] == word[0] && check_match(x, y, 1, visited, board, word))
                    return true;
            }
        }
        return false;

    }
