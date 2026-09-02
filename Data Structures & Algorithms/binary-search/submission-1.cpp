class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int size  = nums.size();
        // if(target < nums[size / 2])
        // {
        //     for(int i = 0; i < size / 2; i++)
        //         if(target == nums[i])
        //             return i;
        // }
        // else
        // {
        //     for(int i = size / 2; i < size; i++)
        //         if(target == nums[i])
        //             return i;
        // }
        // return -1;
        int r = nums.size() - 1;
        int l = 0;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(target == nums[mid])
                return mid;
            else if(target < nums[mid])
            {
                r = mid - 1 ;
            }
            else
                l = mid + 1;
        }
        return -1;

    }
};
