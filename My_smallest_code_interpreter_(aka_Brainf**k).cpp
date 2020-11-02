
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

map<char, int> plus_min={{'+',1},{'-',-1}};
map<char, int> less_more={{'<',-1},{'>',1}};
map<char, int> brc_val={{'[',1},{']',-1}};
map<char, char> brc_pair={{'[',']'},{']','['}};



std::string brainLuck(const std::string &code, const std::string &input) {


  size_t code_ptr=0;
  size_t data_ptr = code_ptr;
  vector<int> data(9999);
  string output;
  string temp = input;
  while(code_ptr!=code.size())
  {
    
    
    char inst = code[code_ptr];
    
    if(inst =='.')
      output.push_back(data[data_ptr]);
    
    if(inst==',')
      {
      
      data[data_ptr] = int(temp[0]);
      temp = temp.substr(1);
      }
    
    if(less_more.find(inst)!=less_more.end())
    {
      data_ptr +=less_more[inst];
      if(data_ptr == data.size())
        data.push_back(0);
    }
    
    if(plus_min.find(inst)!=plus_min.end())
    {
      data[data_ptr]+=plus_min[inst];
      data[data_ptr]%=256;
    }
    
    if((inst=='[' && data[data_ptr]==0) || (inst==']' && data[data_ptr]!=0) )
    {
      auto direc = brc_val[inst];
      auto counter = direc;
      while(!(code[code_ptr]==brc_pair[inst] && counter==0))
      {
        code_ptr+=direc;
        if(brc_val.find(code[code_ptr])!=brc_val.end())
          counter+=brc_val[code[code_ptr]];
      }
     
    }
     code_ptr+=1;
    
    
    
  }
  
  
  cout<<output<<endl;
  
  
  return output;
}


























/* BESTCODE

#include <string>
#include <vector>

std::string brainLuck(std::string code, std::string input)
{
    // stored mapped brace positions to prevent repeated string parsing
    std::map<size_t, size_t> open_brace, close_brace;
    std::vector<size_t> open_brace_stack;

    size_t pos = code.find_first_of( "[]" );
    while( pos != std::string::npos )
    {
        if( code[pos] == '[' )
        {
            open_brace_stack.push_back( pos );
        }
        else // ']':
        {
            open_brace.insert( std::make_pair( pos, open_brace_stack.back() ) );
            close_brace.insert( std::make_pair( open_brace_stack.back(), pos ) );
            open_brace_stack.pop_back();
        }

        pos = code.find_first_of( "[]", pos+1 );
    }

    // Iterate through instructions
    std::string output;
    std::vector<char> data = { (char)0 };
    size_t data_ptr=0;

    for( size_t code_ptr=0; code_ptr < code.size() && code_ptr != std::string::npos; code_ptr++ )
    {
        switch( code[code_ptr]  )
        {
            case ',':
                      data[data_ptr] = input.back();  
                      input.pop_back(); 
                      break;
            case '>': 
                      if( ++data_ptr == data.size() )
                          data.push_back( (char)0 );
                      break;

            case '<': --data_ptr; break;
            case '.': output.push_back( (char)data[data_ptr] ); break;
            case '+': data[data_ptr] = data[data_ptr] ==(char)255 ? (char)0 : (char)data[data_ptr]+1; break;
            case '-': data[data_ptr] = data[data_ptr] ==(char)0 ? (char)255 : (char)data[data_ptr]-1; break;
            case '[': 
                      if( data[data_ptr] == (char)0 )
                          code_ptr = close_brace.find( code_ptr )->second;
                      break;
            case ']':
                      if( data[data_ptr] != (char)0 )
                          code_ptr = open_brace.find( code_ptr )->second;;
                      break;
            default:
                      break;
        }
    }
    
    if( output.size() > 0 )
        return output;
    else
        return input;
}





*/
