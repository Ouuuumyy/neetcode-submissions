class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits;
        for(int num = 0; num <= n; num++)
        {

            int k = 0;
            for(int i = 0; i < 32; i++)
            {
                if((1 << i) & num)
                    k++;
            }
            bits.push_back(k);
        }
        return bits;
    }
};
