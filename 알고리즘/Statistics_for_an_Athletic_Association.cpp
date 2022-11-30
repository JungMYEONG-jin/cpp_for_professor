#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;


class Stat
{
public:
  static std::string stat(const std::string &strg)
  {
    
    if (strg.empty())
    return "";
  string res;
  
  stringstream sstr(strg);
  
  vector<long> rest;
  while (getline(sstr, res, ' '))
  {
    auto prev = res.find('|');
    int h = stoi(res.substr(0, prev));
    auto next = res.find('|', prev + 1);
    int m = stoi(res.substr(prev + 1, next - prev - 1));
    int s = stoi(res.substr(next + 1));
    cout << h << " " << m << " " << s << endl;
    rest.push_back(h * 3600 + m * 60 + s);

  }
  sort(rest.begin(), rest.end());
  long min = rest[rest.size() - 1] - rest[0];
  cout << min / 3600 << " " << min % 3600 / 60 << " " << min % 60 << endl;

  auto total = accumulate(rest.begin(), rest.end(), 0);
  total /= rest.size();
  cout << total / 3600 << " " << total % 3600 / 60 << " " << total % 60 << endl;

  auto median = 0;
  if (rest.size() % 2 == 1)
    median = rest[rest.size() / 2];
  else
    median = (rest[rest.size() / 2] + rest[rest.size() / 2 - 1]) / 2;
  cout << median / 3600 << " " << median % 3600 / 60 << " " << median % 60 << endl;


  stringstream k;
  k << setw(2) << setfill('0');

  string range = "Range: ";

  k << min / 3600;
  range += k.str() + "|";
  k.str("");
  k << setw(2) << setfill('0');
  k << min % 3600 / 60;
  range += k.str() + "|";
  k.str("");
  k << setw(2) << setfill('0');
  k << min % 60;
  range += k.str() + " ";
  //cout << range;
  k.str("");


  string av = "Average: ";
  k << setw(2) << setfill('0');
  k << total / 3600;
  av += k.str() + "|";
  k.str("");
  k << setw(2) << setfill('0');
  k << total % 3600 / 60;
  av += k.str() + "|";
  k.str("");
  k << setw(2) << setfill('0');
  k << total % 60;
  av += k.str() + " ";
  //cout << av;
  k.str("");









  string med = "Median: ";
  k << setw(2) << setfill('0');
  k << median / 3600;
  med += k.str() + "|";
  k.str("");
  k << setw(2) << setfill('0');
  k << median % 3600 / 60;
  med += k.str() + "|";
  k.str("");
  k << setw(2) << setfill('0');
  k << median % 60;
  med += k.str();
  //cout << med;
  return range + av + med;
    
    
    
    
  }
};

/* BEST CODE

class Stat {
public:
    static string stat(const string &str) {
        vector<size_t> ts;
        string ss = str + ',';
        size_t h, m, s;
        size_t t, sum = 0;
        size_t comma = 0;
        char buffer[50];
        for (size_t i = 0; i < ss.length(); ++i) {
            if (ss[i] == ',') {
                sscanf(ss.c_str() + comma, "%zd|%zd|%zd", &h, &m, &s);
                t = h * 3600 + m * 60 + s;
                ts.push_back(t);
                sum += t;
                comma = i + 1;
            }
        }
        sort(begin(ts), end(ts));
        size_t size = ts.size();
        size_t range = ts.back() - ts.front();
        size_t average = sum / size;
        size_t median = size % 2 ? ts[size / 2] : (ts[size / 2 - 1] + ts[size / 2]) / 2;
        sprintf(buffer, "Range: %02zd|%02zd|%02zd Average: %02zd|%02zd|%02zd Median: %02zd|%02zd|%02zd",
            range / 3600, range / 60 % 60, range % 60,
            average / 3600, average / 60 % 60, average % 60,
            median / 3600, median / 60 % 60, median % 60);
        return buffer;
    }
};





















*/
