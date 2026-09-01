class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> max_q;
        vector<int> max_elements;
        for(int r = 0; r < nums.size(); r++)
        {
            max_q.push({nums[r], r});
            if(r >= k - 1)
            {
                while(max_q.top().second <= r - k)
                    max_q.pop();
                max_elements.push_back(max_q.top().first);
            }
        }
        return max_elements;
    }
};
