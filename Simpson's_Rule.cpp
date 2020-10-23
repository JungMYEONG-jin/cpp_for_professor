#include <cmath>

using namespace std;

double get_f(double x)
{
  return 3 * pow(sin(x), 3) / 2;
  
}


class SimpsonIntegration
{
public:
    static double simpson(int n)
      {
      
    double a  = 0;
    double b = M_PI;
  
    double res1= 0.0, res2 = 0.0;
    double h = (b-a)/(n);
    for (int i = 1; i <= n/2; i++) {
        res1 += get_f(a + (2*i-1)*h);
    }
    for (int i= 1; i <= n/2-1; i++) {
        res2 += get_f(a + 2*(i)*h);
    }

    return (b-a)*(get_f(a) + get_f(b) + 4*res1 + 2*res2)/3.0/(n);
      
      
    }
};
