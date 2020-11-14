using namespace std;



std::vector<int> xbonacci(std::vector<int> signature, int n)
{
    // Your code here
  
   int size = signature.size();
    
  if(n<=0)
    return {};
  
  
    for(int i=size-1;i<n;i++)
    {
      int n=0;
      int j=i;
      int temp = size;
      while(temp>0)
      {
        n+=signature[j--];
        temp--;
        
      }
      signature.push_back(n);
    }
  
  
    
    signature.pop_back();
    return signature;
    
    
  }
  
  /* BEST CODE
  
  std::vector<int> xbonacci(std::vector<int> signature, int n)
  {
  
  int size = signature.size();
  signature.resize(n);
  for(int i=size;i<n;i++)
  {
  for(int j=1;j<=size;j++)
  {
  signature[i]+=signature[i-j];
  }
  }
  return signature;
  
  
  
  }
  
  
  
  
  
  
  
  
  */
  
