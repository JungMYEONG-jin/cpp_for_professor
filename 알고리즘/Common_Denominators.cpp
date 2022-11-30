using namespace std;

long long gcd(long long a, long long b)
{
  long long c;
  while(b!=0)
  {
    c = a%b;
    a=b;
    b=c;
  }
  return a;
}

long long lcm(long long a, long long b)
{

return a*b/gcd(a,b);
}

class Fracts
{

public:
    static std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst)
    {
      vector<long long> denom;
      for(auto vec : lst)
      {
        denom.push_back(vec[1]);
      }
      /*
      vector를 선언하지 말고 lcm 구현하여 바로 가능
      long long lcma =1;
      for(auto i : lst)
      {
        lcma = lcm(lcma, i[1]);
      }
      
      
      */
      
      
      long long k = denom[0];
      for(int i=1;i<denom.size();i++)
      {
        k = k*denom[i]/gcd(k, denom[i]);
      }
      string res;
      for(auto vec : lst)
      {
        long long child = k/vec[1];
        res+="("+to_string(child*vec[0])+","+to_string(k)+")";
      }
      
      return res;
    }
};
