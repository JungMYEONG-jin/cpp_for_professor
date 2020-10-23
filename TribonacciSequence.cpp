#incldue<vector>

using namespace std;


std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    std::vector<int> result;
    
    if(n==0 || signature.size()<3)
      return {};
  
  
    if(n<=signature.size())
    {
      for(int i=0;i<n;i++)
        result.push_back(signature[i]);
      return result;
    }
  

  
    auto n1 = signature[0];
    auto n2 = signature[1];
  auto n3 = signature[2];
  result.push_back(n1);
  result.push_back(n2);
  result.push_back(n3);
  for(int i=3;i<n;i++)
  {
    auto n4 = n1+n2+n3;
    result.push_back(n4);
    n1=n2;
    n2=n3;
    n3=n4;
    
  }
  
  
    return result;
}




/* Best code

std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    if(n<3){
       signature.resize(n);
    }
    for(unsigned int i = 3; i<n;i++){
      signature.push_back(signature[i-3]+signature[i-2]+signature[i-1]);
    }
    return signature;
}








*/
