class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size() <= 0)
            return(position.size());
        vector<pair<int, int>> cars;
        int i = 0;
        stack<float> fleets;
        vector<float> arr_time(position.size());
        while(i < position.size())
        {
            pair<int, int> new_pair = make_pair(position[i], speed[i]);
            cars.push_back(new_pair);
            i++;
        }
        sort(cars.begin(), cars.end());
        for(int i = 0; i < cars.size(); i++)
        {
            arr_time[i] = (float)(target - cars[i].first) / cars[i].second;
        }
        fleets.push(arr_time[position.size() - 1]);
        for(int i = position.size() - 2; i >= 0; i--)
        {
            if(arr_time[i] <= fleets.top())
                continue;
            else
                fleets.push(arr_time[i]);   
        }
        return fleets.size();
    }
};
