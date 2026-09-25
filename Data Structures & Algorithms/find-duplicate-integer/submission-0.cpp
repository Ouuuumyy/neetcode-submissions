class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> dup;
        for(int i = 0; i < nums.size(); i++)
        {
            if(dup.find(nums[i]) == dup.end())
                dup.insert(nums[i]);
            else
                return nums[i];
        }
    }
};
