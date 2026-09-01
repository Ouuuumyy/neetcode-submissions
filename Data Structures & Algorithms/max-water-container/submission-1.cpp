class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int mult = 0;
        int res = 0;
        while(i < j)
        {
            mult = (j - i) * min(heights[i], heights[j]); 
            res = max(res, mult);
            if(heights[i] < heights[j])
                i++;
            else
                j--;
        }
        return res;
    }
};
