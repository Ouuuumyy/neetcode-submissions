class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        vector<int> s1_freq(26);
        vector<int> window_freq(26);
        int l = 0;

        for(char c : s1)
            s1_freq[c - 'a']++;

        for(int r = 0; r < s2.length(); r++)
        {
            window_freq[s2[r] - 'a']++;

            if(r - l + 1 == s1.length())
            {
                if(s1_freq == window_freq)
                    return true;
                else
                {
                    window_freq[s2[l] - 'a']--;
                    l++;
                }
            }
        }
        return false;
    }
};
