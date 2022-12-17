## 투포인터


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* cur = head;
            ListNode* res = head;
            for(int i=0;i<n;i++)
                cur = cur->next;
        
            if(cur==nullptr){
                head = head->next;
                return head;
            }
            while(cur->next!=nullptr){
                res = res->next;
                cur = cur-> next;
            }
        res->next = res->next->next;
        return head;
    }
};
```
