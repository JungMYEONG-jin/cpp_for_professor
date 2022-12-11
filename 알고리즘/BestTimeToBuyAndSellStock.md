## DP인줄 알았으나 간단한 구현이었음..

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0]; // init buy
        int profit = 0;
        int res = 0;

        for(int i=1,len=prices.size();i<len;i++)
        {
            buy = min(buy, prices[i]);
            int prev = profit;
            profit = max(profit, prices[i]-buy);
            if(profit!=prev && profit>0){
                res+=profit;
                profit = 0;
                buy = prices[i];
            }
        }
        return res;

    }
};
```
