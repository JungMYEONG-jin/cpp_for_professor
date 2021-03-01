#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <regex>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <sstream>

using namespace std;

typedef long long ll;

int root[100001];

int find(int x)
{
    if (root[x] == x)
        return x;
    return root[x]= find(root[x]);
}

void unions(int x, int y)
{
    x = find(x);
    y = find(y);
    root[x] = y;
}







int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.tie(NULL);
    
    int g, p;
    cin >> g >> p;
    for (int i = 1; i <= g; i++)
        root[i] = i;
    int gi;
    int count = 0;
    for (int i = 1; i <= p; i++)
    {
        
        cin >> gi;
        auto k = find(gi);
        if (k != 0)
        {
            unions(k, k - 1);
            count++;
        }
        else
            break;

    }
    cout << count;

    return 0;
}
