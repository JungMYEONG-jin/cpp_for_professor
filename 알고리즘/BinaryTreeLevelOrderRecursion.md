```c++
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
}

void dfs(TreeNode* root, int idx, vector<vector<int>>& result){
    if (root == NULL)
    {
        return ;
    }
    if(idx>=result.size()){
        result.push_back({root->val});
    }else{
        result[idx].push_back(root->val);
    }

    dfs(root->left, idx+1, result);
    dfs(root->right, idx+1, result);
}
```
