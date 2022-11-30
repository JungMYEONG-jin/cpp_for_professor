using namespace std;

std::string solve(std::string s){
  //..  
  
  string a = s;
  reverse(a.begin(), a.end());
  string temp;
  string res;
  
  for(auto i : a)
  {
    if(isalpha(i))
      res+=i;
    else if(isdigit(i))
    {
      int k = i-'0'-1; //already one checked
      temp = res;
      
      while(k--) res+=temp;
    }
  }
  
  reverse(res.begin(), res.end());
  return res;
}
