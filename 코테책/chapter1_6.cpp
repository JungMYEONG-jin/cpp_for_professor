#include <iostream>
#include <string>

using namespace std;


int main()
{

string key, plain;
getline(cin, key);
getline(cin, plain);
string copy = plain;
int len = key.size();
for(int i=0;i<plain.size();i++)
{

	plain[i]^=key[i%len];
}

cout<<plain<<endl;
cout<<copy<<endl;

cout<<"복호화진행"<<endl;

for(int i=0;i<plain.size();i++)
{

plain[i]^=key[i%len];
}

cout<<plain<<endl;

}
