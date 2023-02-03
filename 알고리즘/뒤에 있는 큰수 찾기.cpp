#include <string>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

vector<int> solution(vector<int> numbers) {
    int len = numbers.size();
    vector<int> answer(len);
    stack<int> res;
	for (int i = 0; i < len; i++) {
		while (!res.empty() && numbers[res.top()] < numbers[i]) {
			answer[res.top()] = numbers[i];
			res.pop();
		}

		res.push(i);
	}

	while (!res.empty()) {
		answer[res.top()] = -1;
		res.pop();
	}
    return answer;
    
}
