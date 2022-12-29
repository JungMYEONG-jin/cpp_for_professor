## Two pointer

중복값이 존재하면 존재하는 만큼 이동
아니라면 값 추가

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
    ListNode* deleteDuplicates(ListNode* head) {

        // 임시 헤드
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        // 이전 
        ListNode* prev = temp;
        // 현재
        ListNode* cur = head;
        while(cur){
            // 중복값을 찾는다.
            while(cur->next && cur->val == cur->next->val){
                cur = cur->next;
            }
            // 만약 중복이 아니라면 진행
            if(prev->next == cur)
                prev = prev->next;
            else
                prev->next = cur->next; // 중복만큼 건너 뛰기
            cur = cur->next;
        }

        return temp->next;
    }
};
```
