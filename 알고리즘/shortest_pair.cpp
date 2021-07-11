#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

typedef long long ll;
#define inf LLONG_MAX;



pair<int, int> arr[500000];

ll check(vector<pair<int, int>>& res){
for(int i=1, sz= res.size();i<sz;i++)
{
if(res[i].first==res[i-1].first && res[i].second==res[i-1].second)
{
cout<<0<<endl;
return 0;
}

}
return 1;
}

ll dist(pair<int, int> a, pair<int, int> b){

return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);

}



ll brute_force(vector<pair<int, int>>& res, ll s, ll e){
ll mmn = dist(res[s], res[e]);
for(ll i =s;i<=e;i++)
{
for(ll j =i+1;j<=e;j++)
{
mmn = min(mmn, dist(res[i], res[j]));
}


}
return mmn;
}



ll find(ll cuti, ll loc, ll p){

for(ll i = loc;i<p;i++)
{
if(arr[i].second>cuti)
	return i;
}
return p;
}

ll near(vector<pair<int, int>>& res, ll s, ll e){
ll mid = (s+e)>>1;
ll d;
ll k = res[mid].first;
ll p =0;
ll te=0;
ll mmn = inf;
ll uu;
if(e-s<=5)
	return brute_force(res, s, e);
d = min(near(res, s, mid), near(res, mid+1, e));
uu = sqrt(d)+1;


// y sorting
for(int i=s;i<=e;i++)
{
if(k-uu<=res[i].first && res[i].first<=k+uu)
{

arr[p++] = res[i];
}

}

sort(arr, arr+p, [](auto e, auto k){return e.second<k.second;});

for(ll ts=0;ts<p;ts++)
{
te = find(arr[ts].second+uu, te, p);
for(ll i = ts+1;i<te;i++)
{
mmn = min(mmn, dist(arr[ts], arr[i]));
}

}


return min(d, mmn);
}



int main()
{
int a, b, c, d;
cin>>a>>b>>c>>d;


vector<pair<int, int>> res;

res.push_back({0, 2});
res.push_back({1, 1});
res.push_back({1, 7});
res.push_back({2, 5});
res.push_back({4, 4});
res.push_back({7, 5});
res.push_back({7, 6});
res.push_back({8, 7});
res.push_back({10, 9});
res.push_back({8, 10});
sort(res.begin(), res.end());
int len = res.size();



if(check(res))
{
cout<<near(res, 0,len-1);
}



}
