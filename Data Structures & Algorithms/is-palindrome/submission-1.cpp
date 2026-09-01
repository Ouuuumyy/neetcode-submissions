class Solution {
public:
    // bool isPalindrome(string s) {
    //     string valid = "";
    //     for(int i = 0; i < s.length(); i++)
    //     {
    //         char c = tolower(s[i]);
    //         if(isalnum(c))
    //             valid += c;
    //     }
    //     int len = valid.length();
    //     for(int i = 0; i < (len / 2); i++)
    //     { 
    //         if(valid[i] != valid[len - i -1])
    //             return false;
    //     }
    //     return true;
    // }


    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while(left < right)
        {
            while(left < right && !isalnum(s[left]))
                left++;
            while(left < right && !isalnum(s[right]))
                right--;
            if(tolower(s[left]) != tolower(s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
};
