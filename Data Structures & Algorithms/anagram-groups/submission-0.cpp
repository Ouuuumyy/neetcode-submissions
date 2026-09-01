class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> groups;

        for(string s : strs)
        {
            int nums[26] = {0};
            for(int j = 0; j < s.length(); j++)
            {
                nums[s[j] - 'a']++;
            }
            string res = "";
            for(int i = 0; i < 26; i++)
            {
                res += to_string(nums[i]) + "#";
            }
            groups[res].push_back(s);    
        }
        vector<vector<string>> result;
        for(auto it = groups.begin(); it != groups.end(); it++)
        {
            result.push_back(it->second);
        }
        return result;
    }
};
