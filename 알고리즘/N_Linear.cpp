
#include <vector>
#include <queue>
#include <limits>
using namespace std;


uint32_t n_linear(const std::set<uint32_t>& m, size_t n)
{
    // TODO return nth element of U(m)
  vector<uint32_t> res(m.begin(), m.end());
  
  int len = m.size();
  vector<queue<uint32_t>> que(len);
  vector<uint32_t> idx(len);
  
  
  vector<uint32_t> temp{1};
  
  size_t count = 0;
  for(int i=0, lens= res.size();i<lens;i++)
    que[i].push(res[i]+1);
  
  
  while(count!=n)
  {
    long long min  = 92233720368545807;
    
    for(int i=0;i<len;i++)
    {
      if(que[i].front()<min)
        min = que[i].front();
        
    }
    temp.push_back(min);
    
    for(int i=0;i<len;i++)
    {
      if(que[i].front()==min)
      {
        que[i].pop();
        idx[i]++;
        que[i].push(res[i]*temp[idx[i]]+1);
      }
    }
    count++;
    
  }
  
  
  
  return temp.back();
  
  
}



















/* BEST CODE
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

uint32_t n_linear(const std::set<uint32_t>& m, size_t n) {
    int k = m.size();
    vector<uint32_t> num(m.begin(), m.end());
    vector<uint32_t> idx(k, 0), res{1}, val;
    for (auto& x : num) val.push_back(x + 1);
    for (int t = 1; t <= n; ++t) {
        uint32_t x = *min_element(val.begin(), val.end());
        res.push_back(x);
        for (int i = 0; i < k; ++i)
            if (val[i] == x)
                val[i] = num[i] * res[++idx[i]] + 1;
    }
    return res.back();
}






*/
