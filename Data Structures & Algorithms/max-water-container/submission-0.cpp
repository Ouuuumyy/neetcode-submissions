class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int mul = 0;
        int res = 0;
        while(i < j)
        {
            mul = (j - i) * min(heights[i], heights[j]); 
            if(res < mul)
                res = mul;
            if(heights[i] < heights[j])
                i++;
            else
                j--;
        }
        return res;
    }
};
