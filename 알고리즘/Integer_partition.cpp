#include <map>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>
#include <sstream>
#include <iomanip>
using namespace std;

static map<long long, set<long long>> memo;

class IntPart
{
public:
	static std::string part(long long n);
};


set<long long> Prod(long long n)
{
	if (memo.find(n) != memo.end())
	{
		return memo[n];
	}
	set<long long> temp;
	temp.insert(n);
	for (int i = 1; i <= n / 2; i++)
	{
		set<long long> proded = Prod(n - i);
		for (auto c : proded)
		{
			temp.insert(c * i);
		}
	}
	memo.insert(make_pair(n, temp));
	return temp;

}

string IntPart::part(long long n)
{
	set<long long> temp = Prod(n);
	long long min = *temp.begin();
	long long max = *max_element(temp.begin(), temp.end());
	double avg = 0;
	double median = 0;
	long long size = temp.size();
	long long count = 0;
	long long prev = 0;

	for (auto a : temp)
	{
		avg += (double)a / (double)size;
		if (size % 2 == 0 && count == (size / 2))
		{
			median = (double)(a + prev) / 2.0f;
		}
		else if (size % 2 == 1 && count == size / 2)
		{
			median = a;
		}
		count++;
		prev = a;
	}

	stringstream sstr;
	sstr << fixed;
	sstr << setprecision(2);
	
	sstr << "Range: "<< max-min<<" Average: "<< avg<< " Median: " <<median;
	return sstr.str();
}







/* BEST CODE


class IntPart
{
public:
  static std::string part(long long n)
  {
	std::vector<std::set<long long> > prods;
	prods.push_back(std::set<long long>());
	prods[0].insert(1);

	long long i = 1;
	while (i <= n)
	{
	  prods.push_back(std::set<long long>());
	  for (long long j = 1; j <= i; j++)
	  {
		for (auto p : prods[i - j])
		  prods[i].insert(p * j);
	  }
	  i++;
	}

	double average = 0.0, median = 0.0;
	std::set<long long> &lastProds = *prods.rbegin();
	int range = *lastProds.rbegin() - *lastProds.begin();
	i = 1;
	for (auto it = lastProds.begin(); it != lastProds.end(); ++it)
	{
	  if (lastProds.size() % 2 == 0 && (i == lastProds.size() / 2 || i == lastProds.size() / 2 + 1))
		median += 0.5 * (*it);
	  else if (lastProds.size() % 2 == 1 && i == lastProds.size() / 2 + 1)
		median = *it;
	  average += (double) *it / lastProds.size();
	  i++;
	}

	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << "Range: " << range << " Average: " << average << " Median: " << median;
	return stream.str();
  }
};








*/











int main()
{

	cout << IntPart::part(1) << endl;
	cout << IntPart::part(2) << endl;
	cout << IntPart::part(3) << endl;
	cout << IntPart::part(4) << endl;
	cout << IntPart::part(5) << endl;

	


	
}