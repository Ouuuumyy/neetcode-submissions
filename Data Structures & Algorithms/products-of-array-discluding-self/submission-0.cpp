class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 1;
        int s = 1;
        int len = nums.size();
        int n = len - 1;

        vector<int> prefix(len);
        vector<int> suffix(len);
        
        for(int i = 0; i < len; i++)
        {
            prefix[i] = p;
            suffix[n] = s;
            p *= nums[i];
            s *= nums[n];
            n--;
        }
        vector<int> res(len);

        for(int i = 0; i < nums.size() ; i++)
        {
            res[i] = prefix[i] * suffix[i];
        }
        return res;
    }
};
