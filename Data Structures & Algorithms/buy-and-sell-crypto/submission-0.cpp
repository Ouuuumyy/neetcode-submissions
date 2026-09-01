class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int L = 0;
        int profit = 0;
        for(int R = 1; R < prices.size(); R++)
        {
            if(prices[R] > prices[L])
            {
                profit = max(profit, prices[R] - prices[L]);
            }
            else
            {
                L = R;
            }
        }
        return profit;
    }
};
