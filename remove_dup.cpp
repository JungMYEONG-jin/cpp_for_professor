#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

//std::erase(이하 erase) 함수는 해당 인덱스의 데이터를 지우고 그 뒤에 있는 데이터를 남은 자리만큼 앞으로 이동시킨다.
// 어차피 erase 함수가 실행되면 배열의 뒷요소가 자동으로 당겨지기 때문에 erase가 실행되지 않을때만 인덱스 증가해줘야함




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
간편한 코드


*/

int main()
{
    vector<int> a{ 1,2,1,2,1,2,3};

    vector<int> b = solve(a);

    for (const auto& i : b)
        cout << i << endl;
}