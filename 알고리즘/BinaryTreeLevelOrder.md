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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> temp;
            int qsize = q.size();
            for(int i=0;i<qsize;i++){
                auto it = q.front();
                q.pop();
                temp.push_back(it->val);

                if(it->left != NULL){
                     q.push(it->left);
                }

                if(it->right != NULL){
                     q.push(it->right);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};
```
