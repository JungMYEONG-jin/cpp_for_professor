int getFirst(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int mid;
	int first = -1;
	int last = -1;
	vector<int> res;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (nums[mid] < target) {
			left = mid + 1;
		}
		else if (nums[mid] > target) {
			right = mid - 1;
		}
		else {
			first = mid;
			right = mid - 1;
		}
	}
	return first;
}

int getLast(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int mid;
	int last = -1;
	vector<int> res;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (nums[mid] < target) {
			left = mid + 1;
		}
		else if (nums[mid] > target) {
			right = mid - 1;
		}
		else {
			last = mid;
			left = mid + 1;
		}
	}
	return last;
}

vector<int> searchRange(vector<int>& nums, int target) {
	return { getFirst(nums, target), getFirst(nums, target) };
}
