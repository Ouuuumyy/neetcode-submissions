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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode *, int>> levels;
        int good = 0;
        if(!root)
            return 0;
        levels.push({root, root->val});
        while(!levels.empty())
        {     
            
            auto [curr, maxSoFar] = levels.front();

            levels.pop();
            if(curr->val >= maxSoFar)
                good++;
            if(curr->left)
                levels.push({curr->left, max(maxSoFar, curr->val)});
            if(curr->right)
                levels.push({curr->right, max(maxSoFar, curr->val)});         
        }
        return good;
    }
};
