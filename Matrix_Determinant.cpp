#include <iostream>
#include <vector>

using namespace std;

long long determinant(vector< vector<long long> > m)
{

	if (m.size() == 1)
	{
		return m[0][0];

	}
	else if (m.size() == 2)
	{
		return m[0][0] * m[1][1] - m[0][1] * m[1][0];
	}

	long long res = 0;
	int sign = 1;

	for (int i = 0; i < m.size(); i++)
	{
		vector<vector<long long>> sub;
		for (int j = 1; j < m.size(); j++)
		{
			vector<long long> temp;
			for (int k = 0; k < m.size(); k++)
			{
				if (k != i)
					temp.push_back(m[j][k]);
			}
			sub.push_back(temp);
		}
		res += determinant(sub) * m[0][i] * sign;
		sign *= -1;
	}



	return res;


}






/*  BEST CODE

#include <iostream>
#include <vector>

using namespace std;

long long determinant(vector< vector<long long> > m) {
  if (m.size() == 1) return m[0][0];
  long long result = 0;
  for (int i = 0; i < m.size(); i++) {
    vector< vector<long long> > submatrix;
    for (int j = 1; j < m.size(); j++) {
      vector<long long> row;
      for (int k = 0; k < m.size(); k++) if (k != i) row.push_back(m[j][k]);
      submatrix.push_back(row);
    }
    result += determinant(submatrix) * (i % 2 == 0 ? m[0][i] : -m[0][i]);
  }
  return result;
}

*/
