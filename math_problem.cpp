   #include <iostream>
   #include <vector>
   #include <numeric>
   
   using namespace std;
   
   
   int main()
   {
   
   
   
   int T;
        int left;
        int right;
        cin >> T;
        vector<vector<int>> res(15, vector<int>(15, 0));

        for (int i = 0; i < 1; i++)
        {
            for (int j = 1; j <= 14; j++)
                res[i][j] = j;
        }

        for (int i = 1; i <= 14; i++)
        {
            for (int j = 1; j <= 15; j++)
                res[i][j-1] = accumulate(res[i-1].begin(), res[i-1].begin() + j, 0);
        }

        vector<int> test(T);
        for (int i = 0; i < T; i++)
        {
            cin >> left;
            cin >> right;
            test[i] = (res[left][right]);
        }

        for (auto i : test)
            cout << i << '\n';
    }
