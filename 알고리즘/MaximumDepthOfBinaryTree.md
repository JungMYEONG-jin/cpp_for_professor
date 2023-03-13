
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
    int depth = 0;

    void traverse(TreeNode* root, int val){
        if(root == NULL)
            return;

        if(root->left == NULL && root->right == NULL)
            depth = max(depth, val);
        traverse(root->left, val+1);
        traverse(root->right, val+1);
    }


    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        traverse(root, 0);
        return depth+1;
    }
};
```
