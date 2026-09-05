class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_n = 0;
        for(int i = 0; i < piles.size(); i++)
            max_n = max(max_n, piles[i]);
        int l = 1;
        int r = max_n;
        int k = 0;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            long long sum = 0;
            for(int i = 0; i < piles.size(); i++)
            {
                long long hours = piles[i] / mid;
                if(piles[i] % mid != 0)
                    hours++;    
                sum += hours;
            }
            if(sum <= h)
            {
                k = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return k;
    }
};
