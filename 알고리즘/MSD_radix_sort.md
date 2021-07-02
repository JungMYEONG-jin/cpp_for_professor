# MSD radix sort

1. left to right 방식으로 정렬해간다.
2. not stable 하다는 단점이 존재함.
3. 최악의 경우 ~2NW가 됨. N 배열의 크기, W 문자열의 최대 길이
4. 평균적으로 NlogN임. 이때 log의 밑 지수는 사용하는 문자 코드의 최대 갯수에 의해 결정됨. 확장된 Ascii code라면 r은 256이다.
5. 3-way radix quick sort도 존재함.
6. quick sort보다 빠르다.


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



void msd_sort(vector<string>& arr, vector<string>& aux, int low, int high, int d)
{
	if (low >= high)
		return;

	vector<int> count(258); // ascii 256자이므로 R은 256임 맨끝 맨처음 포함해야하므로 2자리 추가

	for (int i = low; i <= high; i++)
		count[arr[i][d] + 2]++; //문자열에 대한 각각의 문자에 대한 counting

	for (int r = 0; r < 257; r++)
		count[r + 1] += count[r];

	for (int i = low; i <= high; i++)
	{
		aux[count[arr[i][d] + 1]++] = arr[i];
	}

	for (int i = low; i <= high; i++)
		arr[i] = aux[i - low];

	for (int r = 0; r < 256; r++)
		msd_sort(arr, aux, low + count[r], low + count[r + 1] - 1, d + 1);

}

void msd_sort(vector<string>& arr)
{
	vector<string> aux(arr.size());
	msd_sort(arr, aux, 0, arr.size() - 1, 0);
}


int main()
{

	vector<string> res;

	res.push_back("now"); res.push_back("for"); res.push_back("tip"); res.push_back("ace"); res.push_back("ilk"); res.push_back("dim"); res.push_back("tag");
	res.push_back("jot"); res.push_back("sob"); res.push_back("nob"); res.push_back("sky"); res.push_back("hut"); res.push_back("bet"); res.push_back("men");
	res.push_back("egg"); res.push_back("few"); res.push_back("jay"); res.push_back("owl"); res.push_back("joy"); res.push_back("rap"); res.push_back("gig");
	res.push_back("wee"); res.push_back("was"); res.push_back("cab"); res.push_back("wad"); res.push_back("caw"); res.push_back("cue"); res.push_back("fee");
	res.push_back("tap"); res.push_back("ago"); res.push_back("tar"); res.push_back("jam"); res.push_back("dug"); res.push_back("and");
	cout << "원본 배열\n\n";
	for (auto i : res)
		cout << i << '\n';
	cout << endl;
	msd_sort(res);
	cout << "After MSD Sort\n\n";
	for (auto i : res)
		cout << i << '\n';



}

```


## 결과값

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
