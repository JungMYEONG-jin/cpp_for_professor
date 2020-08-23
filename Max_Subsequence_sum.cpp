#include <iostream>
#include <vector>


using namespace std;


int maxSequence(const vector<int>& arr) {
    //...
    if (arr.empty())
        return 0;

    int sum = 0;
    int sumax = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum < 0)
            sum = 0;
        if (sumax < sum)
            sumax = sum;

    }

    return sumax;


}


int main()
{

    vector<int> arr{ 1,2,3,4,5 };
    vector<int> test{ -1,-2,0 };

    cout << maxSequence(arr) << endl;
    cout << maxSequence(test) << endl;



}