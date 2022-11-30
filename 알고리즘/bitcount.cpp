#include <iostream>
#include <bitset>


using namespace std;
unsigned int countBits(unsigned long long n) {
	//your code here

	bitset<64> bb = n;

	return bb.count();

}

int main()
{

	cout << countBits(76765197376770) << endl;





}