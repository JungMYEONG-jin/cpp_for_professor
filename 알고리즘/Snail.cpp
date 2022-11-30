#include <iostream>
#include <vector>


using namespace std;


vector<int> Snail(vector<vector<int>>& smap)
{
	if (smap[0].size() == 0)
		return {};

	int n = smap.size();

	ptrdiff_t col = 0, row = 0, pcol = 0, prow = 0, bcol = n - 1, brow = n - 1;

	vector<int> res;

	while (prow <= brow)
	{
		while (col < bcol) res.push_back(smap[row][col++]); prow++;
		while (row < brow) res.push_back(smap[row++][col]); bcol--;
		while (pcol < col) res.push_back(smap[row][col--]); brow--;
		while (prow < row) res.push_back(smap[row--][col]); pcol++;
	}

	res.push_back(smap[row][col]);


	return res;

}

int main()
{

	vector<vector<int>> test{ {1,2,3,4},{12,13,14,5},{11,16,15,6},{10,9,8,7} };

	auto k = Snail(test);

	for (auto it : k)
		cout << it << ' ';
	cout << endl;



}