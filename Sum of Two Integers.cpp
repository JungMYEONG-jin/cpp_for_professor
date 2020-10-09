int Add (int x, int y)
{
  // Your Code Is Here ... Enjoy !!
  while(y!=0)
    {
    int carry = x&y;
    x=x^y;
    y=carry<<1;
  }
  
  return x;
}
