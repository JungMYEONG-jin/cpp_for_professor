#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int maxRow = 0;
    int minCol = 0;
    for(int i=0, len = sizes.size();i<len;i++){
        vector<int> arr = sizes[i];
        int row = max(arr[0], arr[1]);
        int col = min(arr[0], arr[1]);
        maxRow = max(row, maxRow);
        minCol = max(col, minCol);
    }
    
    answer = maxRow*minCol;
    
    return answer;
}
