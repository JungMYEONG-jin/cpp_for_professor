#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getScore(vector<string>& board, char ch) {
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == ch && board[i][1] == board[i][0] && board[i][2] == board[i][1])
            cnt++;
        if (board[0][i] == ch && board[1][i] == board[0][i] && board[2][i] == board[1][i])
            cnt++;
    }
    // check 대각선
    if (board[0][0] == ch && board[1][1] == board[0][0] && board[2][2]==board[1][1])
        cnt++;
    if (board[0][2] == ch && board[1][1] == board[0][2] && board[2][0]==board[1][1])
        cnt++;
    return cnt;
}

int solution(vector<string> board) {
    int o=0, x=0;
    for (auto str : board) {
        for (char ch : str)
        {
            if (ch == 'O')
                o++;
            else if (ch == 'X')
                x++;
        }
    }
    cout<<o<<" "<<x<<endl;

    if (x > o || o - x > 1)
        return 0;
    if (getScore(board, 'O') > 0 && getScore(board, 'X') > 0)
        return 0;
    if (getScore(board, 'O') > 0)
    {
        if(o == x)
            return 0;
    }
    if (getScore(board, 'X') > 0)
    {
        if(o > x)
            return 0;
    }
    return 1;
}
