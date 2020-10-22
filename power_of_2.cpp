unsigned long long solution ( unsigned long long n )
{
  long long k=1;
  
  if(n%2==1)
    return 1;
  
  if(n%2==0)
    {
    
    while(n%2==0)
    {
      n/=2;
      k*=2;
    }
    
    
  }
  
  return k;
}
