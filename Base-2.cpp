#include <iostream>
#include <string>
/* MYCODE

#include <string>


using namespace std;

int pow(int n)
{
  if(n==0)
    return 1;
  else if(n==1)
    return -2;
  
  if(n%2==1)
  {
    return pow(n-1)*(-2);
  }
  int half = pow(n/2);
  return half*half;
}



class Negabinary{
public:
  static std::string ToNegabinary(int i)
  {
    
    string res;
    if(i==0)
      return "0";
    while(abs(i)>0)
    {
      int rem = i%(-2);
      i = i/(-2);
      
      if(rem<0)
      {
        rem+=2;
        i++;
      }
      res+=to_string(rem);
    }
    reverse(res.begin(), res.end());
    return res;
    
  }
  static int ToInt(std::string s)
    {
    
    int sum=0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]-'0'==1)
        sum+=pow(s.size()-i-1);
    }
    return sum;
    
  }
};



















*/








#include <cmath>

class Negabinary{
public:
  static std::string ToNegabinary(int value);
  static int ToInt(std::string binary);
};

std::string Negabinary::ToNegabinary(int value)
{
  if (value == 0)
      return "0";

  std::string binaryVal ("");
  while(value != 0) {
      int remainder = value % -2;
      value /= -2;

      if (remainder < 0) {
        remainder += 2;
        value++;
      }
      binaryVal = std::to_string(remainder) + binaryVal;
  }
  return binaryVal;
}

int Negabinary::ToInt(std::string binary)
{
  int decimalVal(0);
  int bits = binary.size();
  for (int i = 0; i < bits; ++i) {
    decimalVal += (char(binary[bits - i - 1]) - '0') * pow(-2, i);
  }
  return decimalVal;
}
