#include <vector>
#include <map>
using namespace std;

vector <int> sortTwisted37 (vector <int> numbers) {
  
  vector<int> res;
 // sort(numbers.begin(), numbers.end());
  for(int i=0;i<numbers.size();i++)
  {
    string k = to_string(numbers[i]);
    for(int j=0;j<k.size();j++)
    {
      if(k[j]=='3')
        k[j]='7';
      else if(k[j]=='7')
        k[j]='3';
    }
    
    numbers[i]=stoi(k);
    
  }
  sort(numbers.begin(), numbers.end());
   for(int i=0;i<numbers.size();i++)
  {
    string k = to_string(numbers[i]);
    for(int j=0;j<k.size();j++)
    {
      if(k[j]=='3')
        k[j]='7';
      else if(k[j]=='7')
        k[j]='3';
    }
    
    numbers[i]=stoi(k);
    
  }
  
  return numbers;
}
