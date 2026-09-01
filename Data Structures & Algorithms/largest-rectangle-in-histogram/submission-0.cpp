class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area= 0;
        stack<int> tall;
        for(int i  = 0; i <= heights.size(); i++)
        {
            int current_h;
            if(i == heights.size())
                current_h = 0;
            else
                current_h = heights[i];
            while(!tall.empty() && current_h < heights[tall.top()])
            {
                int index = tall.top();
                int H = heights[index];
                tall.pop();
                int W = 0;
                if(tall.empty())
                    W = i;
                else
                    W = i - tall.top() - 1;
                max_area = std::max(max_area, W * H);
            }

            tall.push(i);
        }
        return max_area;
    }
};
