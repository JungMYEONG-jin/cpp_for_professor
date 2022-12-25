## DP

모든 레벨의 마지막 노드는 right 값이므로 계속 돌아서 마지막 값이 될때를 넣어주면 된다.


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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int qsize = q.size();
            while(qsize--){
                TreeNode* it = q.front();
                q.pop();
                if(qsize==0){
                    res.push_back(it->val);
                }
                if(it->left)
                    q.push(it->left);
                if(it->right)
                    q.push(it->right);
            }
        }
        return res;
    }
};
```
