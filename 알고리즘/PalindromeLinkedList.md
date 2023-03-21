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

Time O(N) Space O(1) 방법

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

    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
            if(fast)
                fast = fast->next;
        }
        return slow;
    }

ListNode* reverseList(ListNode* head){
    ListNode* prev = NULL;
    ListNode* temp = NULL;
    ListNode* cur = head;
    
    while(cur != NULL){
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

bool compareList(ListNode* left, ListNode* right){
    while(left!=NULL && right!=NULL){
        if(left->val != right->val)
            return false;
        left = left->next;
        right = right->next;
    }
    return true;
}



    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode* h = head;
        ListNode* mid = findMid(h);
        ListNode* rev = reverseList(mid);
        return compareList(head, rev);
    }
};
```
