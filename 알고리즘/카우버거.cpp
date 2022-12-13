#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <set>
#include <numeric>
#include <cmath>
#include <stack>

#define INF 1000000000

using namespace std;

int primes[5000001];

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* temp = list1;
    ListNode* temp2 = list2;
    vector<int> res;
    while (temp != nullptr) {
        res.push_back(temp->val);
        temp = temp->next;
    }

    while (temp2 != nullptr) {
        res.push_back(temp2->val);
        temp2 = temp2->next;
    }
    sort(res.begin(), res.end());

    ListNode* result = (ListNode*)malloc(sizeof(ListNode));
    for (auto i : res) {
        result->val = i;
        result = result->next;
    }
    return result;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int burger, side, drink;
    cin >> burger >> side >> drink;

    vector<int> burgers(burger);
    vector<int> sides(side);
    vector<int> drinks(drink);
    for (int i = 0; i < burger; i++)
        cin >> burgers[i];
    for (int i = 0; i < side; i++)
        cin >> sides[i];
    for (int i = 0; i < drink; i++)
        cin >> drinks[i];

    sort(burgers.begin(), burgers.end(), [](auto it, auto it2) {return it > it2; });
    sort(sides.begin(), sides.end(), [](auto it, auto it2) {return it > it2; });
    sort(drinks.begin(), drinks.end(), [](auto it, auto it2) {return it > it2; });

    int origin = accumulate(burgers.begin(), burgers.end(), 0) + accumulate(sides.begin(), sides.end(), 0) + accumulate(drinks.begin(), drinks.end(), 0);
    int sum = 0;
    int idx1 = 0;
    int idx2 = 0;
    int idx3 = 0;
    while (idx1 < burger && idx2 < side && idx3 < drink) {
        sum += static_cast<int>((burgers[idx1++] + sides[idx2++] + drinks[idx3++]) * 0.9);
    }
    while (idx1 < burger)
        sum += burgers[idx1++];
    while (idx2 < side)
        sum += sides[idx2++];
    while (idx3 < drink)
        sum += drinks[idx3++];
    cout << origin << '\n' << sum;

   
}
// 2335
