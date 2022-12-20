## dfs로 해결

우선 해당 노드가 nullptr인지 그리고  left가 nullptr인지 확인한다. binary tree 자식은 왼쪽부터라서 그럼.
없다면 탈출함. 있다면 root->left->next =root->right;
그리고 만약 root->next가 존재하면
root->right->next = root->next->left 가 된다.
이걸 left, right 반복하면됨.
```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    void dfs(Node* root){
        if(root == nullptr || root->left == nullptr)
            return;
        root->left->next = root->right;
        if(root->next!=nullptr)
            root->right->next = root->next->left;
        dfs(root->left);
        dfs(root->right);
    }

    Node* connect(Node* root) {
        if(root==nullptr)
            return root;
        dfs(root);
        return root;
    }
};
```
