class Solution {
private:
    void backTrack(vector<int>& nums, int start,vector<int> &curr, vector<vector<int>> &results)
    {
        results.push_back(curr);
        
        for(int i = start; i < nums.size(); i++)
        {
            curr.push_back(nums[i]);
            backTrack(nums, i + 1, curr, results);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> curr;
        backTrack(nums,0, curr, results);
        return results;
    }
};
