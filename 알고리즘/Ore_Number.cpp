#include <cmath>

using namespace std;


bool isOre(unsigned int n){
  
  double sum = 0.0;
  int count=0;
  for(int i=1;i<=sqrt(n);i++)
  {
    if(n%i==0)
    {
      if(n/i == i)
      {
        sum+=n/(double)i;
        count++;
      }
      else
      {
        sum+=n/(double)i;
        sum+=n/(double)(n/i);
        count+=2;
      }
    }
  }
  sum = sum/n;
  double mean  = count/sum;
  cout<<n<<" "<<sum<<" "<<mean<<endl;
 
  return mean==floor(mean)?true:false;
  
  
  
}
