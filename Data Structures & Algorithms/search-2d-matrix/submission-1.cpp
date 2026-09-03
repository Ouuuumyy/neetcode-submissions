class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m * n - 1;

        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            int mid_value = matrix[mid / n][mid % n];
            if(target == mid_value)
            {
                return true;
            }
            else if(target < mid_value)
                r = mid - 1;
            else
                l = mid + 1;
        }
    
        return false;
    }
};
