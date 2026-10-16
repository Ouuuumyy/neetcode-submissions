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
        vector<vector<int>> vectors;
        if(!root)
            return vectors;
        queue<TreeNode*> que;
            
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int> currLevel;
            for(int i = 0; i < size; i++)
            {
                TreeNode *curr = que.front();
                que.pop();
                if(curr->left)
                    que.push(curr->left);
                if(curr->right)
                    que.push(curr->right);
                currLevel.push_back(curr->val);
            }
        
            vectors.push_back(currLevel);
        }
        return vectors;

    }
};
