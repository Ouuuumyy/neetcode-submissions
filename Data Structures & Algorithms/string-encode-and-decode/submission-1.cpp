class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string s : strs)
        {
            res += to_string(s.length()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        for(int i = 0; i < s.length();)
        {
            int pos = i;
            while(s[pos] != '#')
            {
                pos++;
            }
            int len = 0;
            for(int j = i; j < pos; j++)
            {
                 len = len * 10 + (s[j] - '0'); 
            }
            i = pos + 1;
            strs.push_back(s.substr(i, len));
            i += len;
        }
        return strs;
    }
};
