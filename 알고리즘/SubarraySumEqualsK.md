```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> db;
        int cnt = 0;
        int sum = 0;

        for(int i=0, len = nums.size();i<len;i++){
            sum += nums[i];

            if(sum == k)
                cnt++;
            if(db.find(sum-k) != db.end())
                cnt += db[sum-k];

            db[sum]++;
         }
        return cnt;
    }
};
```
