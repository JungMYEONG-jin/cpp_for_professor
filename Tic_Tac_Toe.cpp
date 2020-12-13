#include<string>
#include<vector>

using namespace std;

std::string displayBoard(const std::vector<char>& board, unsigned short width){
  //your code here
  
  string res = " ";
  int count = width;
  int num = 0;
  for(int i =0;i<count;i++)
  {
    if(i!=count-1)
      res+=string(1,board[i])+" | ";
    else if(i==count-1)
    {
      num++;
      count+=width;
      res+=string(1,board[i])+" ";
      if(num!=board.size()/width)
        res+="\n"+string(4*width-1, '-')+"\n ";
      
      if(i==board.size()-1)
      {
        return res;
      }
      
    }

    
    cout<<res<<endl;
  }
  cout<<res<<endl;
  return res;
}









/* BEST CODE




#include <string>
#include <vector>
#include <sstream>

std::string displayBoard(const std::vector<char>& board, unsigned short width){
    std::ostringstream oss;
    unsigned int count = 0;
    auto end = board.size();
    std::string rowsSeparator(width*4-1, '-');
    for(const auto& i : board) {
        count++;
        oss << ' ' << i << ' ';
        if(count == end)
            break;
        else if(count%width == 0)
            oss << '\n' << rowsSeparator << '\n';
        else
            oss << '|';
    }
    return oss.str();
}


*/
