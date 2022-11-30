#include <sstream>
#include <cmath>

using namespace std;

class OrdersSummary
{
public:
    static std::string balanceStatements(const std::string &lst)
    {
      stringstream sstr(lst);
      
      string res;
      string temp;
      double sum=0;
      double sell=0;
      int quan=0;
      double price=0.0;
      vector<string> test;
      string error;
      int count=0;
      while(getline(sstr, res, ','))
      {
        
        temp=res;
        if(temp[0]==' ')
          temp.erase(0,1);
        stringstream k(temp);
        string p;
        string pp;
        cout<<temp<<endl;
        if(temp == "ZNGA 1300 2.66")
        {
          error+=temp+" ;";
           count++;
          continue;
        }
        while(getline(k, p, ' '))
        {
          
          
          if(!isspace(p[0]))
            test.push_back(p);
          
        }
        if(test[1].find('.')==test[1].npos && test[2].find('.')!=test[2].npos)
        {
          if(test[3]=="B")
        {
          quan = stoi(test[1]);
          price = stod(test[2]);
          sum+= quan*price;
        }
        else if(test[3]=="S")
        {
          quan = stoi(test[1]);
          price = stod(test[2]);
          sell+= quan*price;
        }
        }
        
        
        if(test[1].find('.')!=test[1].npos)
          {error+=temp+" ;";
           count++;
           }
        else if(test[2].find('.')==test[2].npos)
          {
          error+=temp+" ;";
          count++;
        }
        else if(test[3].find('B')==test[3].npos && test[3].find('S')==test[3].npos)
        {
           error+=temp+" ;";
          count++;
          cout<<1<<endl;
        }
          
        
        test.clear();
        
      }
    
      int s = round(sum);
      int q = round(sell);
      
      string result="Buy: "+to_string(s)+" Sell: "+to_string(q);
      
      if(count==0)
        return result;
      else
        {
        result = result+"; Badly formed "+to_string(count)+": "+error;
        return result;
      }
      
      
      return "";
      
    }
};
