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
    bool isValidBST(TreeNode* root) {
        vector<int> temp;
        inorder(root, temp);
        return isSorted(temp);
    }

    void inorder(TreeNode* root, vector<int>& temp){
        if(root!=NULL){
            inorder(root->left, temp);
            temp.push_back(root->val);
            inorder(root->right, temp);
        }
    }

    bool isSorted(vector<int>& temp){
        int len = temp.size();
        for(int i=1;i<len;i++){
            if(temp[i-1] >= temp[i])
            {
                return false;
            }
        }
        return true;
    }
};
```
