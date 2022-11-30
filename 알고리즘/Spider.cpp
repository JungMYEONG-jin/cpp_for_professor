#include <cmath>
#include <string>

using namespace std;

double spider_to_fly(const std::string& spider, const std::string& fly) {
  
  auto a = spider[1]-'0';
  auto b = fly[1]-'0';
  
  string angle = "CBAHGFED";
  
  
  double ans = abs((int)angle.find(spider[0])-(int)angle.find(fly[0]))*45;
  cout<<ans<<" "<<a<<" "<<b<<endl;
  cout<<cos(ans/(180/M_PI))<<endl;
  double side =0;
  
  side = sqrt(abs(a*a+b*b-2*a*b*cos(ans/(180/M_PI))));
  
    
    
  
  return side;
}
