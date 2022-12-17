## 투포인터를 이용해 중간 지점 구하기.

중간 지점을 구할애는 one by one 으로 가고, 나머지는 one by two로 진행 그러면 end에 닿으면 나머진 중간 지점이다!


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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;
  
        if (head!=NULL)
        {
            while (fast_ptr != nullptr && fast_ptr->next != nullptr)
            {
                fast_ptr = fast_ptr->next->next;
                slow_ptr = slow_ptr->next;
            }    
        }
        return slow_ptr;
    }
};
```
