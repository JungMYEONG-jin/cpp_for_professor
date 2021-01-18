#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

char triangle(const string &row)
{
   vector<int> temp;
  
  for(int i=9;i>=0;i--)
  {
    int j = pow(3, i)+1;
    if(i-1<=100000)
      temp.push_back(j);
    
    
  }
string res;
string rows = row;
for(int i=0;i<temp.size();i++)
{
    
    int len = temp[i];
    
    while(rows.size()>=len)
    {
        for(int j=0;j<rows.size()-len+1;j++)
        {
            
            
        if(rows[j]==rows[j+len-1])
        {
            res.push_back(rows[j]);
        }else
        {
            string test="RGB";
            auto it = find(test.begin(), test.end(),rows[j]);
            //cout<<*it<<endl;
            if(it!=test.end())
            {
                test.erase(it);
            }
            auto it2= find(test.begin(), test.end(),rows[j+len-1]);
            if(it2!=test.end())
            {
                test.erase(it2);
            }
            res.push_back(test[0]);
            //cout<<test[0]<<endl;
        }
    
       
        }
        rows = res;
        res.clear();
    }// while
    
    
} // for
 return rows[0];
}




//BEST CODE

/*


#include <map>
#include <string>
using namespace std;
char triangle(string r){
  map<string, char> mp = {{"RR", 'R'}, {"BB", 'B'}, {"GG", 'G'}, {"BG", 'R'}, {"BR", 'G'}, {"GB", 'R'}, {"GR", 'B'}, {"RB", 'G'}, {"RG", 'B'}};
  while(r.size() > 1){
    string n = "";
    int c = 1;
    while(r.size() % (3 * c) == 1) c *= 3;
    for (int i = 0; i < r.size() - 1; i += c){
        string x = "";
        x += r[i];
        x += r[i + c];
        n += mp[x];
    }
    r = n;
  }
  return r[0];
}





*/
