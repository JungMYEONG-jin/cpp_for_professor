#include <iostream>
#include <vector>


using namespace std;


// 구할 값이 나오고 두 수를 더해서 index return

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
    

    for (int i = 0; i < numbers.size(); i++)
    {


        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[i] + numbers[j] == target)
                return { i,j };
        }




    }

}



int main()
{
    vector<int> a{ 1,2,3 };
    vector<int> b{ 1234, 5678, 9012 };
    auto p = two_sum(a, 4);
    auto k = two_sum(b, 14690);

    cout << p.first << " " << p.second << endl;
    cout << k.first << " " << k.second << endl;




}