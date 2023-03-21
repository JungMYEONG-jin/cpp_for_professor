```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> res;
        if(head == NULL)
            return false;
        
        while(head != NULL){
            res.push_back(head->val);
            head = head->next;
        }

        vector<int> temp = res;
        reverse(temp.begin(), temp.end());
        return temp == res;
    }
};
```
