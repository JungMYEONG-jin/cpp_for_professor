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

#include <queue>

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;

        // for bfs

        queue<TreeNode*> q;
        queue<int> s;

        q.push(root);
        s.push(root->val);

        while(!q.empty()){
            TreeNode* it = q.front();
            q.pop();
            int sum = s.front();
            s.pop();

            if(it->left == NULL && it->right == NULL){
                if(sum == targetSum)
                    return true;
            }
            if(it->left != NULL){
                q.push(it->left);
                s.push(sum+(it->left->val));
            }

            if(it->right != NULL){
                q.push(it->right);
                s.push(sum+(it->right->val));
            }
        }
        return false;
    }
};
```
