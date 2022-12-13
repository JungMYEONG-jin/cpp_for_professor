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

    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        cin >> res[i];
    sort(res.begin(), res.end(), [](auto it, auto it2) {return it > it2; });
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += res[i];
        if ((i + 1) % 3 == 0)
            sum -= res[i];
    }
    cout << sum << endl;

   
}
// 2335
