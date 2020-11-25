double v(int k, int n)
{
  double r = 1.0;
  r/=k*pow(n+1,2*k);
  return r;
}


class Magnets
{
public:
    static double doubles(int maxk, int maxn)
    {
      double r =0.0;
      for(int i=1;i<=maxk;i++)
        for(int j=1;j<=maxn;j++)
          r+=v(i,j);
      
      return r;
      
    }
};
