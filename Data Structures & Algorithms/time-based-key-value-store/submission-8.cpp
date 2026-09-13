class TimeMap {
private:
    map<string, vector<pair<string, int>>> vals;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        vals[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        if(vals.find(key) == vals.end())
            return "";
        const vector<pair<string, int>>& find_vals = vals[key];
        int l = 0;
        int r = find_vals.size() - 1;
        string max = "";
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            int val = find_vals[mid].second;
            if(val == timestamp)
                return find_vals[mid].first;
            else if(val > timestamp)
                r = mid - 1;
            else
            {
                max = find_vals[mid].first;
                l = mid + 1;
            }    
        }
        return max;
    }
};
