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
#include <cmath>
#include <math.h>

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int l = getHeight(root->left);
        int r = getHeight(root->right);

        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        return max(l + r, max(leftDiameter, rightDiameter));
    }

    int getHeight(TreeNode* root){
        if(root == NULL)
            return 0;
        return 1+ max(getHeight(root->left), getHeight(root->right)); 
    }
};
# 위 방법은 재귀로 풀었더니 Time O(N^2) 가 걸려서 그런지 성능이 매우 낮게 나왔다..

#include <cmath>
#include <math.h>

class Solution {
public:

    int diameterWithHeight(TreeNode* root, int* height){

    int lh = 0;
    int rh = 0;

    int ldia = 0;
    int rdia = 0;

     if (root == NULL)
    {
        *height = 0;
        return 0;
    }

     ldia = diameterWithHeight(root->left, &lh);
     rdia = diameterWithHeight(root->right, &rh);

    *height = max(lh, rh) + 1;

    return max(lh + rh , max(ldia, rdia));
}


    int diameterOfBinaryTree(TreeNode* root) {
        int height = 0;
        return diameterWithHeight(root, &height);
    }

    
};

# 위 방법은 높이를 같은 재귀에서 구해 두번 반복하는걸 줄였음.

```
