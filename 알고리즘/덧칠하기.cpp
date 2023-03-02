#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    stack<int> st;
    int len = section.size();
    for (int i = len - 1; i >= 0; i--) {
        st.push(section[i]);
    }

    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        answer++;
        // check cur + m -1 <=n
        if (cur + m - 1 <= n) {
            while (!st.empty() && st.top() <= cur + m - 1) {
                st.pop();
            }
        }
        else {
            while (!st.empty() && st.top() <= n) {
                st.pop();
            }
        }
    }

    return answer;
}


bool a[200000];
int solution2(int n, int m, vector<int> section) {
    int answer = 0;
    for(int i = 0; i < section.size(); i++){
        a[section[i]] = 1;
    }

    for(int i = 1; i <= n; i++){
        if(a[i]){
            answer++;
            for(int j = 0; j < m; j++){
                a[i + j] = 0;
            }
        }
    } 
    return answer;
}
