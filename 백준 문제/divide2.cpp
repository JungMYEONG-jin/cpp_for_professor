#include <iostream>
#include <vector>


using namespace std;

int neg_color=0;
int color0=0;
int color1=0;

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

check_color(arr, start, end, num/3);
check_color(arr, start+num/3, end, num/3);
check_color(arr, start+2*num/3, end, num/3);
check_color(arr, start+num/3, end+num/3, num/3);
check_color(arr, start, end+num/3, num/3);
check_color(arr, start, end+2*num/3, num/3);
check_color(arr, start+num/3, end+2*num/3, num/3);
check_color(arr, start+2*num/3, end+2*num/3, num/3);
check_color(arr, start+2*num/3, end+num/3, num/3);
flag=true;
break;

}

}


}

if(!flag)
{

if(color==1)
	color1++;
else if(color==0)
	color0++;
else
	neg_color++;

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

cout<<neg_color<<'\n'<<color0<<'\n'<<color1;







}
