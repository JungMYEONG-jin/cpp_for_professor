#include <string>
#include <unordered_map>

using namespace std;

std::unordered_map<char, char> pairs = {{'A', 'T'}, {'T', 'A'}, {'C', 'G'}, {'G', 'C'}};

std::string DNAStrand(const std::string& dna)
{
  //your code here
  
  string res="";
  for(auto & c : dna)
    res+=pairs[c];
  return res;
  
}
