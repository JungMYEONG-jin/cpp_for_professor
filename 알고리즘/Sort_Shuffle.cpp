#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <map>

using namespace std;


int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    {
        vector<int> arr = { 1,8,3,5,6,2,9,4,10,7 };

        for (auto i : arr)
            cout << i << " ";
        cout << endl;
        int len = arr.size();
        for (int i = 0; i < len; i++)
        {
            int k = arr[i];
            auto it = min_element(arr.begin() + i + 1, arr.end());
            if (it != arr.end() && k > * it)
            {
                swap(arr[i], arr[it - arr.begin()]);
            }
        }

        for (auto i : arr)
            cout << i << " ";
        cout << endl;


    }

    {
        vector<int> arr = { 1,8,3,5,6,2,9,4,10,7,99,11,13 };

        for (auto i : arr)
            cout << i << " ";
        cout << endl;
        int len = arr.size();
        for (int i = 0; i < len; i++)
        {
            int k = arr[i];
            int prev = *max_element(arr.begin()+i, arr.end());
            int idx = 0;
            bool flag = false;
            for (int j = i + 1; j < len; j++)
            {
                if (arr[j] < arr[i] && arr[j]<prev)
                {
                    prev = arr[j];
                    idx = j;
                    flag = true;
                }
            }
            if(flag)
                swap(arr[i], arr[idx]);
        }

        for (auto i : arr)
            cout << i << " ";
        cout << endl;


    }
    
    {
        vector<int> arr = { 1,8,3,5,6,2,9,4,10,7,99,11,13 };

        for (auto i : arr)
            cout << i << " ";
        cout << endl;
        int len = arr.size();
        for (int i = 0; i < len; i++)
        {
            int k = arr[i];
            int idx = i;
            bool flag = false;
            for (int j = i + 1; j < len; j++)
            {
                if (arr[j] < arr[idx])
                    idx = j;
            }
            swap(arr[i], arr[idx]);
        }

        for (auto i : arr)
            cout << i << " ";
        cout << endl;


    }

    {
        vector<int> arr = { 1,8,3,5,6,2,9,4,10,7,99,11,13 };
        // insertion sort
        for (auto i : arr)
            cout << i << " ";
        cout << endl;
        int len = arr.size();
        for (int i = 0; i < len; i++)
        {
            for (int j = i; j >0; j--)
            {
                if (arr[j] < arr[j-1])
                {
                    swap(arr[j], arr[j - 1]);
                }
                else
                    break;
            }
            
        }

        for (auto i : arr)
            cout << i << " ";
        cout << endl;


    }

    // shuffle 알고리즘
    // i=0부터 시작시
    // int r = i+rand()%(52-i);

    // i=len-1 부터 시작시
    //  int r = rand()%(i+1);


    // random device 사용시
    // random_device rd
    // mt19937 gen(rd());
    /*
    for(int i =51;i>0;i--)
    {
    uniform_int_distribution<decltype(i)> dist(0,51);
    swap(arr[i], arr[dist(gen)])

    }
    
    */
    


    {
        int arr[52];
        for (int i = 0; i < 52; i++)
            arr[i] = i + 1;

        

        for (int i = 0; i < 52; i++)
            cout << arr[i] << " ";

        random_device rd;
        mt19937 gen(rd());
        cout << endl;

        for (int i = 51; i > 0; i--)
        {
            uniform_int_distribution<decltype(i)> dist(0, 51);
            swap(arr[i], arr[dist(gen)]);
        }

        for (int i = 0; i < 52; i++)
            cout << arr[i] << " ";

        map<int, int> res;
        for (int i = 0; i < 52; i++)
            res[arr[i]]++;
        cout << endl;
        cout << res.size() << endl;
        for (auto i : res)
            cout << i.first << " " << i.second << endl;
        



        






    }







}
