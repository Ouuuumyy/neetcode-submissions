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
private:
    int validate(TreeNode *node, int minval, int maxval)
    {
        if(!node)
            return true;
        if(node->val <= minval || node->val >= maxval)
            return false;
        return validate(node->left, minval, node->val) &&
            validate(node->right, node->val, maxval);
    }

public:
    bool isValidBST(TreeNode* root) {
        return validate(root, INT_MIN, INT_MAX);
    }
};
