class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> groups;

        for(string s : strs)
        {
            string nums = string(26, '0');
            for(int j = 0; j < s.length(); j++)
            {
                nums[s[j] - 'a']++;
            }
            groups[nums].push_back(s);    
        }
        vector<vector<string>> result;
        for(auto it = groups.begin(); it != groups.end(); it++)
        {
            result.push_back(it->second);
        }
        return result;
    }
};
