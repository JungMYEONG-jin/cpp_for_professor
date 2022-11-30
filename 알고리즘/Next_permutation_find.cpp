#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;




int main() {
  
    
        int n;
        cin >> n;
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            cin >> res[i];

        vector<int> temp = res;
        sort(temp.begin(), temp.end(), greater<int>());
        if (temp == res)
        {
            cout << -1 << endl;
            return 0;
        }
        else
        {
            next_permutation(res.begin(), res.end());
            for (auto i : res)
                cout << i << " ";
            return 0;
        }

       

}
