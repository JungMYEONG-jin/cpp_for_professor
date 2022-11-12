vector<int> solution(vector<int> price) {
	vector<int> ans(price.size());
	stack<int> res;
	for (int i = 0; i < price.size(); i++) {
		while (!res.empty() && price[res.top()] < price[i]) {
			ans[res.top()] = i - res.top();
			res.pop();
		}

		res.push(i);
	}

	while (!res.empty()) {
		ans[res.top()] = -1;
		res.pop();
	}
	return ans;
}
