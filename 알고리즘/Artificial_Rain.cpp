#include <vector>


using namespace std;

bool check_left(const vector<int>& res, long i)
{
  //큰수에서 copy ref가 더 성능이 좋음 복사할 필요가 없다
  // 빅 사이즈인데 계속 copy value하면 매우 느려짐
  
  if(i==0)
    return false;
  return res[i]>=res[i-1];
  
  
}

bool check_right(const vector<int>& res, long i)
{
  //큰수에서 copy ref가 더 성능이 좋음 복사할 필요가 없다
  // 빅 사이즈인데 계속 copy value하면 매우 느려짐
  
  if(i==res.size()-1)
    return false;
  return res[i]>=res[i+1];
  
  
}


int artificialRain(const std::vector<int>& v) {
  // your code here
  
  long len = v.size();
  vector<int> left(len);
  vector<int> right(len);
  vector<int> result(len);
  
  for(long i = 0;i<len;i++)
  {
    
    if(check_left(v, i))
      left[i]=left[i-1]+1;
    else
      left[i]=0;
    
    if(check_right(v, len-i-1))
      right[len-i-1] = right[len-i]+1;
    else
      right[len-i-1]=0;
    
    result[i]+=left[i];
    result[len-i-1]+=right[len-i-1];
    
    
    
  }
  
  
  
  
  
  return *max_element(result.begin(), result.end())+1;
  
  
}
