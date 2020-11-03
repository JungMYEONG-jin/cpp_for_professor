#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct PeakData {
	vector<int> pos, peaks;
};



PeakData pick_peaks(vector<int> v) {
  PeakData result;
  // Your code here

  if (v.empty())
  {

    return result;
  }

  vector<pair<int, int>> temp;
  auto max = 0;
  auto match=false;
  for (int i = 1; i < v.size(); i++)
  {
    if(v[i-1]<v[i])
    {
      max=i;
      match=true;
    }else if(match && v[i-1]>v[i])
    {
      match=false;
      result.peaks.push_back(v[max]);
      result.pos.push_back(max);
    }
    

  }


  return result;
}
