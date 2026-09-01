class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        int counts[26] = {0};
        for(char c : s)
        {
            counts[c - 'a']++;
        }
        for(char c : t)
        {
            counts[c - 'a']--;
        }
        for(int i = 0; i < 26 ; i++)
        {
            if(counts[i] != 0)
                return false;
        }
        return true;
    }

    // bool isAnagram(string s, string t) {
    //     if(s.length() != t.length())
    //         return false;
    //     std::unordered_map<char, int> counts;
    //     for(char c : s)
    //     {
    //         counts[c]++;
    //     }
    //     for(char c : t)
    //     {
    //         counts[c]--;
    //     }
    //     for(auto it = counts.begin(); it != counts.end(); it++)
    //     {
    //         if(it->second != 0)
    //             return false;
    //     }
    //     return true;
    // }
};
