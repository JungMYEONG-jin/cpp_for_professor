#include <iostream>
#include <cstdio>
using namespace std;



int max_of_four(int a, int b, int c, int d)
{
    int arr[4]={a,b,c,d};
    int max=a;
    for(const auto& i : arr)
    {
        if(i>max)
            max=i;
    }
    return max;
}






int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
