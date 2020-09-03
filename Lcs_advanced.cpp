#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;


vector<string> get_sub(string const str)
{
    int size = pow(2, str.size());

    vector<string> res;

    for (int i = 1; i < size; i++)
    {
        string temp = "";
        for (int j = 0; j < str.size(); j++)
        {
            if (i & (1 << j))
                temp += str[j];
        }
        res.push_back(temp);
    }
    return res;
}

string lcs(const string& x, const string& y)
{
    if (x.empty() || y.empty())
        return "";
    

    auto ka = get_sub(x);
    auto pa = get_sub(y);
    auto k = ka.size() < pa.size() ? ka : pa;
    auto p = ka.size() < pa.size() ? pa : ka;



    sort(k.begin(), k.end(), [](string const i, string const j) {return i.size() > j.size(); });

    for (int i = 0; i < k.size(); i++)
    {
        for (int j = 0; j < p.size(); j++)
        {
            if (k[i] == p[j])
                return k[i];
        }
    }
    return "";


   
}



//MyCode
int lcsk[1001][1001] = { 0, };
string seq[1001][1001];
void lcs2(const string& x, const string& y)
{
   

    int l1 = x.length();
    int l2 = y.length();
    string test = "";
    int longest = -1;
    for (int i = 1; i <= l2; i++)
    {
       
        for (int j = 1; j <= l1; j++)
        {
           
            if (y[i - 1] == x[j - 1])
            {
                lcsk[i][j] = lcsk[i - 1][j - 1] + 1;
                seq[i][j] = seq[i - 1][j - 1] + y[i - 1];
                
            }
            else
            {
                if (lcsk[i - 1][j] > lcsk[i][j - 1])
                {
                    lcsk[i][j] = lcsk[i-1][j];
                    seq[i][j] = seq[i-1][j];
                }
                else
                {
                    lcsk[i][j] = lcsk[i][j-1];
                    seq[i][j] = seq[i][j-1];
                }



            }
            if (longest < lcsk[i][j])
            {
                longest = lcsk[i][j];
                test = seq[i][j];
            }
            
        }
       
    }
 
    cout << test << endl;
   
}

//BestCode
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;


string lcs(const string& x, const string& y) {
    if (x.length() == 0 || y.length() == 0) return "";
    int n = x.length(), m = y.length();

    auto dp = vvs(n + 1, vs(m + 1, ""));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (x[i] == y[j]) dp[i + 1][j + 1] = dp[i][j] + string(1, x[i]);
            else dp[i + 1][j + 1] = dp[i][j + 1].size() > dp[i + 1][j].size() ? dp[i][j + 1] : dp[i + 1][j];
        }
    }

    return dp[n][m];
}

int main()
{
    lcs2("anokk", "no");
    lcs2("anothertest", "notatest");
    lcs2("abcdefghijklmnopq", "apcdefghijklmnobq");
    lcs2("nothardlythefinaltest", "zzzfinallyzzz");
    lcs2("132535365", "123456789");
    lcs2("A", "A");
}