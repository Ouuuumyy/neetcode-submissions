class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> my_set;
        if(nums.size() > 0)
        {
            my_set.insert(nums[0]);
            for(int i = 1; i < nums.size(); i++)
            {
                if(my_set.find(nums[i]) != my_set.end())
                    return true;
                my_set.insert(nums[i]);
            }
        }
        return false;
    }
};