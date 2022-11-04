#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    
   
    for (auto card : cards) {
         bool visited[101] = { false, };
        int idx = card;
        int left = 0;
        while (true) {
            if (visited[idx -1])
                break;
            visited[idx -1] = true;
            left++;
            idx = cards[idx - 1];
        }
        vector<int> temp;
        for (int i = 0, len = cards.size(); i < len; i++) {
            if (!visited[i])
                temp.push_back(cards[i]);
        }
        int right = 0;
        for (auto card : temp) {
            int idx2 = card;
            int other = 0;
            while (true) {
                if (visited[idx2-1])
                {
                    right = max(right, other);
                    break;
                }
                visited[idx2 - 1] = true;
                other++;
                idx2 = cards[idx2 - 1];
            }
        }
        answer = max(answer, left * right);
    }
  
    return answer;
}
