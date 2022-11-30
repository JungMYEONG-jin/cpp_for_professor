#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;




// 총 갯수가 10개 이고 서로 count n==s && count w==e 이면 true else false return



bool isValidWalk(std::vector<char> walk) {
	

	int n_count = count(walk.begin(), walk.end(), 'n');
	int s_count = count(walk.begin(), walk.end(), 's');
	int e_count = count(walk.begin(), walk.end(), 'e');
	int w_count = count(walk.begin(), walk.end(), 'w');
	if (walk.size() == 10)
	{
		if ((n_count == s_count) && (e_count == w_count))
			return true;
		return false;
	}
	else
		return false;

	


	

}

using V = vector<char>;

int main()
{



	cout<<isValidWalk(V{ 'n','s' });
	cout<<isValidWalk(V{ 'n','s','n','s','n','s','n','s','n','s','n','s' });
	cout<<isValidWalk(V{ 'e','w','e','w','n','s','n','s','e','w' });
	cout<<isValidWalk(V{ 'n','s','e','w','n','s','e','w','n','s','e','w','n','s','e','w' });
	cout<<isValidWalk(V{ 'n','s','e','w','n','s','e','w','n','s' });
	cout<<isValidWalk(V{ 's','e','w','n','n','s','e','w','n','s' });
	cout<<isValidWalk(V{ 'n','s','n','s','n','s','n','s','n','n' });
	cout<<isValidWalk(V{ 'e','e','e','w','n','s','n','s','e','w' });



}