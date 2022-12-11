
## 간단한 구현

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        int res = 0;
        for(int i=1, len=prices.size();i<len;i++){
            buy = min(prices[i], buy);
            int prev = profit;
            profit = max(profit, prices[i]-buy);
            if(prev!=profit && profit>0){
                res = max(res, profit);
                profit = 0;
            }
        }
        return res;
    }
};

```
