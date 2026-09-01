class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        size_t len = 0;
        unordered_set<char> my_set;
        for(int r = 0; r < s.length(); r++)
        {
            while(my_set.find(s[r]) != my_set.end())
            {
                my_set.erase(s[l]);
                l++;
            }
            my_set.insert(s[r]);
            len = max(len, my_set.size());
        }
        return len;
    }
};
