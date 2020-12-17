#include <sstream>


using namespace std;

long gcd(long a, long b)
{
  while(b!=0)
  {
    long c = a%b;
    a = b;
    b= c;
    
  }
  return a;
}





class ModSystem
{
public:
    static std::string fromNb2Str(int n, std::vector<int> &sys)
    {
      
      long multi = 1;
      for(auto i : sys)
        {
        if(gcd(multi, i)!=1)
           return "Not applicable";
        multi*=i;
         
         }
      if(multi<n)
        return "Not applicable";
     
      
      ostringstream oss;
      for_each(sys.begin(), sys.end(), [&](const int & i){
            oss << '-' << n%i <<'-';
    });
      
      return oss.str();
               
               
               }
};
