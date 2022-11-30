#include <map>

using namespace std;



std::vector<int> deleteNth(std::vector<int> arr, int n)
{
  map<int, int> res;

  for (auto& i : arr)
    res[i]++;

  vector<pair<int, int>> exceed; // 삭제할 정보들
  for (auto& it : res)
    if (it.second > n)
      exceed.push_back(make_pair(it.first, it.second - n));

  reverse(arr.begin(), arr.end());

  for (auto& it : exceed)
  {
    int count = it.second;
    while (count > 0)
    {
      auto pos = find(arr.begin(), arr.end(), it.first);
      arr.erase(pos);

      count--;
    }
  }
  reverse(arr.begin(), arr.end());
  return arr;
}
