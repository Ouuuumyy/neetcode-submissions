class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> numbers;

        for(int j = 0; j < nums.size(); j++)
        {
            int sub = target - nums[j];
            if(numbers.find(sub) != numbers.end())
            {
                std::vector<int> indexes;
                if(j < numbers.find(sub)->second)
                    return (indexes = {j, numbers.find(sub)->second});
                else
                    return (indexes = {numbers.find(sub)->second, j});
            }
            numbers[nums[j]] = j;
        }
    }
};
