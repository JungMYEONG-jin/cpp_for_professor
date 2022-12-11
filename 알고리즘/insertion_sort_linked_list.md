## 단일 연결 리스트에 정렬하면서 삽입하기

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

    ListNode* heads = NULL;
    ListNode* sorted = NULL;

    void push(int val){
        ListNode* newNode = (ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = val;
        newNode->next = heads;
        heads = newNode;
    }

    void sort_insert(ListNode* newNode){
        if(sorted==NULL || sorted->val >= newNode->val){
            newNode->next = sorted;
            sorted = newNode;
        }else{
            ListNode* cur = sorted;
            while(cur->next!=NULL && cur->next->val < newNode->val){
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }

    ListNode* insertionSortList(ListNode* head) {
        ListNode* cur = head;
        while(cur!=NULL){
            ListNode* next = cur->next;
            sort_insert(cur);
            cur = next;
        }
        heads = sorted;
        return heads;
    }
};

```
