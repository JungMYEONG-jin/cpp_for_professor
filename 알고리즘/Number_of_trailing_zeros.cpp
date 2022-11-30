long zeros(long n) {
  
  long long div5=0;

  if(n<=4)
    return 0;
  
  for(long i=5;n/i>=1;i*=5)
  {
    div5+=n/i;
  }
  

  
  return div5;
}
