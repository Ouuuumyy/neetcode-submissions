class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;
        int row = -1;

        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(target >= matrix[mid][0] && target <= matrix[mid][matrix[mid].size() - 1])
            {
                row = mid;
                break;
            }
            else if(target < matrix[mid][0])
                r = mid - 1;
            else
                l = mid + 1;
        }
    
        if(row < 0)
            return false;
        
        l = 0;
        r = matrix[row].size() - 1;
        while( l <= r)
        {
                int mid = l + (r - l) / 2;
                if(target == matrix[row][mid])
                    return true;
                else if(target < matrix[row][mid])
                    r = mid - 1;
                else
                    l = mid + 1;
        }
        return false;
    }
};
