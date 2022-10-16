#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <set>
#include <numeric>
#include <cmath>

#define INF 1000000000

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
	int answer = -1;

	int left = accumulate(queue1.begin(), queue1.end(), 0);
	int right = accumulate(queue2.begin(), queue2.end(), 0);

	queue<long, deque<long>> q1(deque<long>(queue1.begin(), queue1.end()));
	queue<long, deque<long>> q2(deque<long>(queue2.begin(), queue2.end()));

	int cnt = 0;
	while (!q1.empty() && !q2.empty()) {
		if (left > right) {
			int val = q1.front();
			q1.pop();
			q2.push(val);
			left -= val;
			right += val;
			cnt++;
		}
		else if (right > left) {
			int val = q2.front();
			q2.pop();
			q1.push(val);
			left += val;
			right -= val;
			cnt++;
		}
		else
		{
			break;
		}

	}

	if (q1.empty() || q2.empty())
		cnt = -1;
	answer = cnt;
	return answer;
}

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";
	map<char, int> db;
	for (int i = 0, len = survey.size(); i<len; i++) {
		if (choices[i] == 4)
			continue;
		else if (choices[i] < 4) {
			db[survey[i][0]] = db[survey[i][0]] + (4 - choices[i]);
		}
		else if (choices[i] > 4) {
			db[survey[i][1]] = db[survey[i][1]] + (choices[i]-4);
		}
	}

	string arr[] = { "RT", "CF", "JM", "AN" };
	for (int i = 0; i < 4; i++) {
		answer += (db[arr[i][0]] >= db[arr[i][1]] ? arr[i][0] : arr[i][1]);
	}

	return answer;
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, num;
	cin >> n >> m;
	vector<int> res;
	for (int i = 0; i < m; i++) {
		cin >> num;
		res.push_back(num);
	}

	sort(res.begin(), res.end());

	int minValue = 300001;


	int start = 1;
	int last = res.back();
	while (start <= last) {
		int mid = (start + last) >> 1;
		// 6 
		// mid 과자의 길이
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			cnt += res[i] / mid;
			if (res[i] % mid != 0) {
				cnt++;
			}
		}

		if (cnt > n) {
			start = mid + 1;
		}
		else {
			last = mid - 1;
			minValue = mid;
		}
	}
	cout << minValue << endl;



    return 0;

}
