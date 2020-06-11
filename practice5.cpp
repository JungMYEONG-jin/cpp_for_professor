#include <stdio.h>
#include <stdlib.h>


void update(int *a,int *b) {
    // Complete this function
    int test=*a+*b;
    int test2=abs(*a-*b);


    *a=test;
    *b=test2;



}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
