class Solution {
public:
    bool isPalindrome(string s) {
        string valid = "";
        for(int i = 0; i < s.length(); i++)
        {
            char c = tolower(s[i]);
            if(isalnum(c))
                valid += c;
        }
        int len = valid.length();
        for(int i = 0; i < (len / 2); i++)
        {
            std::cout << len << "\n";
            std::cout << valid[i] << "---" <<valid[len - i- 1]; 
            if(valid[i] != valid[len - i -1])
                return false;
        }
        return true;
    }
};
