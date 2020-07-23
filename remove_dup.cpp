#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

//std::erase(���� erase) �Լ��� �ش� �ε����� �����͸� ����� �� �ڿ� �ִ� �����͸� ���� �ڸ���ŭ ������ �̵���Ų��.
// ������ erase �Լ��� ����Ǹ� �迭�� �޿�Ұ� �ڵ����� ������� ������ erase�� ������� �������� �ε��� �����������




std::vector<int> solve(std::vector<int> vec) {
    //..
   

    for (int i = 0; i < vec.size();)
    {
        auto temp = vec[i];
        if (count(vec.begin(), vec.end(), temp) > 1) {
            while (count(vec.begin(), vec.end(), temp) > 1)
            {

                auto it = find(vec.begin(), vec.end(), temp);
                vec.erase(it);

            }
        }
        else
            i++;
    }

    return vec;



}

/*
std::vector<int> solve(std::vector<int> vec){
    std::unordered_set<int> s(vec.rbegin(), vec.rend());
    vec.assign(s.begin(),s.end());
    return vec;
}
������ �ڵ�


*/

int main()
{
    vector<int> a{ 1,2,1,2,1,2,3};

    vector<int> b = solve(a);

    for (const auto& i : b)
        cout << i << endl;
}