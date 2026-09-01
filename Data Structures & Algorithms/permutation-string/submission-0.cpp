class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        vector<int> freq(26);
        int l = 0;
        for(int i = 0; i < s1.length(); i++)
            freq[s1[i] - 97]++;
        for(int r = 0; r < s2.length(); r++)
        {
            freq[s2[r] - 97]--;

            if(r - l + 1 == s1.length())
            {
                int count = 0;
                for(int i = l; i <= r; i++)
                {
                    if(freq[s2[i] - 97] == 0)
                        count++;
                }
                if(count == s1.size())
                    return true;
                else
                {
                    freq[s2[l] - 97]++;
                    l++;
                }
            }
        }
        return false;
    }
};
