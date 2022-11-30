#include <string>
#include <map>
#include <sstream>



using namespace std;

long parse_int(std::string number) {
  map<string, long> n1; map<string, long> n3;map<string, long> n2;
  n1["one"]=1;n1["two"]=2;n1["three"]=3;n1["four"]=4;n1["five"]=5;n1["six"]=6;n1["seven"]=7;n1["eight"]=8;n1["nine"]=9;n1["zero"]=0;
  n2["ten"]=10;n2["eleven"]=11;n2["twelve"]=12;n2["thirteen"]=13;n2["fourteen"]=14;n2["fifteen"]=15;n2["sixteen"]=16;n2["seventeen"]=17;n2["eighteen"]=18;n2["nineteen"]=19;
  n2["twenty"]=20; n2["thirty"] =30; n2["forty"] =40; n2["fifty"] =50; n2["sixty"] =60; n2["seventy"] =70; n2["eighty"] =80; n2["ninety"] =90;
  n3["hundred"]=100; n3["thousand"]=1000; n3["million"]=1000000;   
  
  for(int i=0;i<number.size();i++)
  {
    if(number[i]=='-')
      number[i]=' ';
  }
  
  
  stringstream sstr(number);
  string res;
  string temp;
  long sum=0;
  
  
  
  
  
  while(getline(sstr, res, ' '))
  {
    
    
    
    if(n1.find(res)!=n1.end())
      sum+=n1[res];
    else if(n2.find(res)!=n2.end())
      sum+=n2[res];
    else if(n3.find(res)!=n3.end())
    {
      sum+=n3[res]*(sum%n3[res])-(sum%n3[res]);
    }
    
  }
  
  
  return sum;
}
