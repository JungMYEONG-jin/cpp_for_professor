#include <iostream>
#include <vector>


using namespace std;


int blue=0;
int white=0;

void check_color(vector<vector<int>>& arr, int start, int end, int num)
{

int color = arr[start][end];
bool flag = false;

for(int i=start;i<start+num;i++)
{
if(flag)
	break;

for(int j=end;j<end+num;j++)
{

if(color!=arr[i][j])
{

check_color(arr, start, end, num/2);
check_color(arr, start+num/2, end, num/2);
check_color(arr, start, end+num/2, num/2);
check_color(arr, start+num/2, end+num/2, num/2);

flag=true;
break;

}

}


}

if(!flag)
{

if(color==1)
	blue++;
else
	white++;

}



}






int main()
{

int n;
cin>>n;

vector<vector<int>> res(n, vector<int>(n));

for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
	cin>>res[i][j];

}



check_color(res, 0, 0, n);

cout<<blue<<'\n'<<white;







}
