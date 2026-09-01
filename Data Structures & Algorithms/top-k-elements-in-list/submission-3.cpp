class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for(auto& pair : freq)
        {
            buckets[pair.second].push_back(pair.first);
        }

        vector<int> res;
        for(int i = buckets.size() - 1; i >= 0; i--)
        {
            for(int j = 0; j < buckets[i].size(); j++){
                res.push_back(buckets[i][j]);
                k--;
            }
            if(k == 0)
                break;
        }

        return res;
    }
};
