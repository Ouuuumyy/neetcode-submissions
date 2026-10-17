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
        queue<TreeNode *> levels;
        vector<int> rightView;
        if(!root)
            return rightView;
        levels.push(root);
        while(!levels.empty())
        {
            int size = levels.size();
            rightView.push_back(levels.back()->val);
            for(int i = 0; i < size ; i++)
            {
                TreeNode *curr = levels.front();
                levels.pop();
                if(curr->left)
                    levels.push(curr->left);
                if(curr->right)
                    levels.push(curr->right);
            }
        }
        return rightView;
    }
};
