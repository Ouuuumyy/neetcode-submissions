class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m)
            return(findMedianSortedArrays(nums2, nums1));
        int half_len = (m + n + 1)/2;
        int l = 0;
        int r = n;

        while(l <= r)
        {
            int i = l + (r - l)/2;
            int j = half_len - i;
            int left1_max = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1_min = (i == n) ? INT_MAX : nums1[i];

            int left2_max = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2_min = (j == m) ? INT_MAX : nums2[j];
            if(left1_max <= right2_min && left2_max <= right1_min)
            {

                int max_left = max(left1_max, left2_max);
                int min_right = min(right1_min, right2_min);
                if((m + n) % 2 != 0)
                    return (double)max_left;
                else
                    return (max_left + min_right) / 2.0;
            }
            else if(left1_max > right2_min)
            {
                r = i - 1;
            }
            else if(left2_max > right1_min)
            {
                l = i + 1;
            }    
        }
        return 0.0;
    }
};
