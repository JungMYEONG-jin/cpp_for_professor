#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <climits>
#include <numeric>
#define inf 10000
using namespace std;





int main()
{
   

    vector<vector<int>> a = {
        {0, 5, inf, 8},
        {7, 0, 9, inf},
        {2, inf, 0, 4},
        {inf, inf, 3, 0}
    };

    auto floydWarshall = [](vector<vector<int>>& arr) {
        auto d = arr;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << d[i][j] << " ";
            }
            cout << endl;
        }

        for (int k = 0; k < 4; k++)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (d[i][j] > d[i][k] + d[k][j])
                    {
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
    };

    floydWarshall(a);


}
