#include <iomanip>
using namespace std;


int countDeafRats(const std::string& town)
{
  string ra = town;
  string rat;
  for (auto i : ra)
    if (!isspace(i))
      rat += i;
  // erase space
  int wrong = 0;
  auto p = rat.find('P');
  // 맨왼쪽이거나 맨오른쪽이거나 아니면 사이지점일때 구분
  //cout << rat.substr(0, p) << endl;
  if (p == 0)
  {
    for (int i = 1; i < rat.size(); i += 2)
    {
      if (rat.substr(i, 2) == "~O")
        wrong++;

    }
    //cout << wrong << endl;
    return wrong;

  }
  else if (p == rat.size() - 1)
  {
    for (int i = 0; i < rat.size() - 1; i += 2)
    {
      if (rat.substr(i, 2) == "O~")
        wrong++;
    }
    //cout << wrong << endl;
    return wrong;
  }


  // not left right case 
  // left   P    right   
  // left O~ deaf    right ~O deaf

  string left = rat.substr(0, p);
  string right = rat.substr(p + 1);
  cout << left << " " << right << endl;
  // check left
  for (int i = 0; i < left.size(); i += 2)
  {
    if (left.substr(i, 2) == "O~")
      wrong++;
  }

  //check right
  for (int i = 0; i < right.size(); i += 2)
  {
    if (right.substr(i, 2) == "~O")
      wrong++;
  }


  //cout << wrong << endl;
  return wrong;
}
