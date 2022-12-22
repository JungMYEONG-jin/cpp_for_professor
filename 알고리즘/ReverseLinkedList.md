## 연결리스트 reverse하기

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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)
            return head;
        vector<int> res;
        ListNode* temp = head;
        while(temp){
            res.push_back(temp->val);
            temp = temp->next;
        }

        ListNode* cur = head;
        for (vector<int>::reverse_iterator i = res.rbegin(); i != res.rend(); ++i ) { 
            cur->val = *i;
            cur = cur->next;
        }   
        return head;
    }
};


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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return head;
        ListNode* temp = head->next;
        head->next = nullptr;
        while(temp){
            ListNode* t = temp->next;
            temp->next = head;
            head = temp;
            temp = t;
        }
        return head;
    }
};

```
