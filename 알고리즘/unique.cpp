#include <iostream>
#include <string>
#include <vector>
#include <algorithm>









template <typename T> std::vector<T> uniqueInOrder(std::vector<T>& iterable) {

	std::vector<T> a;
	if(iterable.size()!=0)
		a.push_back(iterable[0]);

	for (int i = 1; i < iterable.size(); i++)
	{
		if (iterable[i] != iterable[i - 1])
			a.push_back(iterable[i]);
		else
			continue;
	}

	return a;
	
	

	//your code here
}
std::vector<char> uniqueInOrder(const std::string& iterable) {
	//your code here
	std::vector<char> a;
	if(iterable.length()!=0)
		a.push_back(iterable[0]);
	for (int i = 1; i < iterable.length(); i++)
	{
		if (iterable[i] != iterable[i - 1])
			a.push_back(iterable[i]);
		else
			continue;
	}

	return a;




}

int main()
{
	std::vector<int> a{ 1,1,2,2,3,3,2 };

	auto b=uniqueInOrder(a);

	for (const auto& i : b)
		std::cout << i << std::endl;

	auto c = uniqueInOrder("");
	for (const auto& i : c)
		std::cout << i << std::endl;

}