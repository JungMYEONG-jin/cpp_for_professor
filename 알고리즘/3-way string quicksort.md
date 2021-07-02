# MSD radix sort에 3-way partition을 적용하기

1. 단순 MSD radix sort보다 재비교와 common prefix에 대한 비교를 하지 않아 더 좋은 성능을 제공함.


```c++
#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>

using namespace std;




void msd_way3_sort(vector<string>& arr, int low, int high, int d)
{
	if (low >= high)
		return;

	int left = low;
	int right = high;
	int v = arr[low][d];
	int i = low + 1;

	while (i <= right)
	{
		int t = arr[i][d];
		if (t < v)
			swap(arr[left++], arr[i++]);
		else if (t > v)
			swap(arr[right--], arr[i]);
		else
			i++;
	}
	msd_way3_sort(arr, low, left - 1, d);
	if (v >= 0)
		msd_way3_sort(arr, left, right, d + 1); // sort 3 subarrays recursively
	msd_way3_sort(arr, right + 1, high, d);
}

void msd_way3_sort(vector<string>& arr)
{
	msd_way3_sort(arr, 0, arr.size() - 1, 0);
}






int main()
{

	vector<string> res;

	res.push_back("now"); res.push_back("for"); res.push_back("tip"); res.push_back("ace"); res.push_back("ilk"); res.push_back("dim"); res.push_back("tag");
	res.push_back("jot"); res.push_back("sob"); res.push_back("nob"); res.push_back("sky"); res.push_back("hut"); res.push_back("bet"); res.push_back("men");
	res.push_back("egg"); res.push_back("few"); res.push_back("jay"); res.push_back("owl"); res.push_back("joy"); res.push_back("rap"); res.push_back("gig");
	res.push_back("wee"); res.push_back("was"); res.push_back("cab"); res.push_back("wad"); res.push_back("caw"); res.push_back("cue"); res.push_back("fee");
	res.push_back("tap"); res.push_back("ago"); res.push_back("tar"); res.push_back("jam"); res.push_back("dug"); res.push_back("and"); res.push_back("ak");
	cout << "원본 배열\n\n";
	for (auto i : res)
		cout << i << '\n';
	cout << endl;
	msd_way3_sort(res);
	cout << "After MSD Sort\n\n";
	for (auto i : res)
		cout << i << '\n';



}

```

# 결과

```
원본 배열

now
for
tip
ace
ilk
dim
tag
jot
sob
nob
sky
hut
bet
men
egg
few
jay
owl
joy
rap
gig
wee
was
cab
wad
caw
cue
fee
tap
ago
tar
jam
dug
and
ak

After MSD Sort

ace
ago
ak
and
bet
cab
caw
cue
dim
dug
egg
fee
few
for
gig
hut
ilk
jam
jay
jot
joy
men
nob
now
owl
rap
sky
sob
tag
tap
tar
tip
wad
was
wee

```
