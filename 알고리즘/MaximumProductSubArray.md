```c++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
            long long ans = INT_MIN;
            long long product = 1;
    
            for (int num : nums) {
            product *= num;
            ans = max(ans, product);
            if (num == 0)
                product = 1;
            }

            product = 1;

            int len = nums.size();
            for (int i = len - 1; i >= 0; i--) {
            product *= nums[i];
            ans = max(ans, product);
            if (nums[i] == 0)
                product = 1;
        }
        return ans;
    }
};
```
