## 재귀를 통해 부분 트리 체크를 진행.

recursion

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool isEqual(TreeNode* tree1, TreeNode* tree2){
        if(tree1 == NULL && tree2 == NULL)
            return true;
        if(tree1 == NULL || tree2 == NULL)
            return false;
        return (tree1->val == tree2->val && isEqual(tree1->left, tree2->left) && isEqual(tree1->right, tree2->right));
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL)
            return true;
        if(root == NULL)
            return false;
        if(isEqual(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
```

