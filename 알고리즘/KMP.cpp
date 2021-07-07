#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <climits>
#include <numeric>
#include <queue>
#include <map>
#include <sstream>
#define inf 10000
using namespace std;


int* table;
int* createTable(string& key)
{
    int j;
    table = (int*)malloc(sizeof(int) * (key.size() + 1));
    table[0] = -1;
    for (int i = 1; i < key.size() + 1; i++)
        table[i] = 0;
    j = 0;

    for (int k = 1; k < key.size(); k++)
    {
        while (key[j] != key[k] && j > 0)
            j = table[j];

        if (key[j] == key[k])
            table[k + 1] = ++j;
    }
    return table;
}

void KMP(string& key, string& pattern)
{
    int* table;
    int len = key.size();
    int p_len = pattern.size();
    int dist = 0;
    int idx = 0;
    int cnt = 0;
    int flag = 0;

    table = createTable(pattern);

    while (true)
    {
        idx = 0;
        if ((idx + dist) + p_len > len)
            break;
        while (key[idx + dist] == pattern[cnt])
        {
            cnt++; // 일치갯수증가
            idx++;
            if (cnt == p_len)
            {
                cout << dist + 1 << "번째에서 찾음\n";
                flag = 1;
                break;
            }
        }

        dist = dist + (cnt - table[cnt]);//이동거리
        cnt = 0;
    }
    if (flag == 0)
        cout << "일치패턴이없음\n";


}




int main()
{
    



    string strin = "abcabdabcabca";
    string pattern = "bca";

    KMP(strin, pattern);


}
