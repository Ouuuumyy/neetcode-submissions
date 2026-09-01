class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<pair<int, int>> appear;
        int n = temperatures.size();
        vector<int> answer(n);

        for(int i = 0; i < temperatures.size(); i++)
        {

            while(!appear.empty() && temperatures[i] > appear.top().first)
            {
                pair<int, int> temp = appear.top();
                answer[temp.second] = i - temp.second;
                appear.pop();
            }
            pair<int, int> my_pair = make_pair(temperatures[i], i);
            appear.push(my_pair);
        }
        return answer;

        
    }
};
