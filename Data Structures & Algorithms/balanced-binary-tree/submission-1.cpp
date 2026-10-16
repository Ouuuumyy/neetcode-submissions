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

    int depth(TreeNode *node)
    {
        if(!node)
            return 0;
        int i = depth(node->right);
        int j = depth(node->left);

        if(i == -1 || j == -1 || abs(i - j) > 1)
            return -1;

        return 1 + max(i, j); 
    }

    bool isBalanced(TreeNode* root) {

        if(depth(root) != -1)
            return true;
        return false;
    }
};
