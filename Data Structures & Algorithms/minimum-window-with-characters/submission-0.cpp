class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> freq;
        unordered_map <char, int> curr;
        int l = 0;
        for(int i = 0; i < t.length(); i++)
            freq[t[i]] += 1;
        int need = freq.size();
        int have = 0;
        int start_index = 0;
        int min_len = INT_MAX;

        for(int r = 0; r < s.length(); r++)
        {
            char c = s[r];

            if(freq.find(s[r]) != freq.end())
                curr[s[r]] += 1;
            if(freq.count(c) && freq[c] == curr[c])
                have++;
            while(have == need)
            {
                c = s[l];
                if(freq.count(c) && freq[c] == curr[c])
                {
                    have--;
                }
                curr[c]--;
                if(r - l + 1 < min_len)
                {
                    start_index = l;
                    min_len = r - l + 1;
                }
                l++;

            }       
        }
        return (min_len == INT_MAX) ? "" : s.substr(start_index, min_len);
    }
};
