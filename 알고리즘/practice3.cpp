#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    int a,b;
    cin>>a>>b;


    for(int i=a;i<=b;i++)
    {   
        switch(i)
    {
        case 1:
            cout<<"one"<<endl;
            break;
        case 2:
            cout<<"two"<<endl;
            break;
        case 3:
            cout<<"three"<<endl;
            break;
        case 4:
            cout<<"four"<<endl;
            break;
        case 5:
            cout<<"five"<<endl;
            break;
        case 6:
            cout<<"six"<<endl;
            break;
        case 7:
            cout<<"seven"<<endl;
            break;
        case 8:
            cout<<"eight"<<endl;
            break;
        case 9:
            cout<<"nine"<<endl; 
        
    }

        if(i>9)
        {
            if(i%2==0)
                cout<<"even"<<endl;
            else
                cout<<"odd"<<endl;
        }
    }




    return 0;
}
