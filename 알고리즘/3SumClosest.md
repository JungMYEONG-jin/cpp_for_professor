 # 투포인터 탐색
 3Sum과 거의 동일함. 투포인터가 핵심이다.
 
 
 ```c++
 int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int prev = 999999;
        int ans = 999999;
        for(int i=0, len = nums.size();i<len-2;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int idx = i;
            int left = i+1;
            int right = len -1;
            while(left<right){
                int sum = nums[idx]+nums[left]+nums[right];
                if(prev>=abs(target-sum)){
                    prev = abs(target-sum);
                    ans = sum;
                }
                if(target<sum){
                    right--;
                }else
                {
                    left++;
                }
            }
        }
        return ans;
    }
```
