#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;



int main()
{



vector<int> score(10);

for(int i=0;i<10;i++)
{
cin>>score[i];
}

auto copy = score;

for(int i=0;i<9;i++)
{
int midx=i;
for(int j=i+1;j<10;j++)
{
if(score[j]<score[midx])
{
midx=j;
}
}

swap(score[i], score[midx]);

}

string grade = "F D D+ C C+ B B+ A A+ A+";

vector<pair<int, string>> res;

stringstream sstr(grade);
string temp;
int idx=0;
while(getline(sstr, temp, ' '))
{
res.push_back({score[idx], temp});
idx++;

}

for(auto i : copy)
{
for(auto j : res)
	if(i==j.first)
	{
		cout<<j.second<<" ";
		break;
	}
}



}
