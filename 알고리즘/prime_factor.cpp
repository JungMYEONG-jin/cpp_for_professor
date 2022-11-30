using namespace std;



std::vector<int> prime_factors(long n){
  // your code here
  vector<int> res;
  
  if(n<=1)
    return {};
  long i =2;
  while(i*i<=n)
  {
    if(n%i==0)
    {
      while(n%i==0)
      {
        n/=i;
        res.push_back(i);
      }
    }
    i++;
  }
  if(n!=1)
    res.push_back(n);
  
 return res; 
}

//SOMEONE ELSE
/*


std::vector<int> prime_factors(long n){
  std::vector<int> obj;
  int p = 2;
  while(p*p <= n) {
    while(n%p == 0) {
      n /= p;
      obj.push_back(p);
    }
    p += 1 + p % 2;
  }
  if(n > 1) obj.push_back(n);
  return obj;
}











*/

