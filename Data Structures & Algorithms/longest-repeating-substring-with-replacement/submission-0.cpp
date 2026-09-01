class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int l = 0;
        int max_len = 0;
        int max_freq = 0;
        for(int r = 0; r < s.length(); r++)
        {
            freq[s[r]]++;
            max_freq = max(max_freq, freq[s[r]]);

            if((r - l + 1) - max_freq > k)
            {
                freq[s[l]]--;
                l++;
            }
            max_len = max(max_len, r - l + 1); 
        }
        return max_len;
    }
};
