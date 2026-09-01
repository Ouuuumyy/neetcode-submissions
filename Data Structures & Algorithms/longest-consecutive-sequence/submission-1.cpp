class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(), nums.end());
        vector<vector<int>> sequences;
        int j = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(numbers.find(nums[i] - 1) == numbers.end())
            {
                vector<int> seq;
                int start = nums[i];
                seq.push_back(start);
                while(numbers.find(start + 1) != numbers.end())
                {
                    seq.push_back(start + 1);
                    start += 1;
                }
                sequences.push_back(seq);
            }
        }

        int len = 0;
        for(int i = 0; i < sequences.size(); i++)
        {
            while(sequences[i].size() > len)
            {
                len = sequences[i].size();
            }
        }
        return len;
    }
};
