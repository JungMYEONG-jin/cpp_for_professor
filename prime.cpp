#include <iostream>

using namespace std;

bool isPrime(int num) {
    // your code here..
   
    if (num <= 1)
        return false;
    for (int i = 2; i < sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
    
}
/*
int main()
{
    for (int i = -5; i <= 100; i++)
        cout << isPrime(i) << endl;


}*/