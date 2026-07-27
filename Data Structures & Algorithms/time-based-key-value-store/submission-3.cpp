class TimeMap {
    int timer = 0;
public:
    unordered_map<string,vector<pair<int,string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        string ans;
        if(store.find(key) == store.end()) return ans;
        int l = 0;
        int r = store[key].size()-1;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(store[key][mid].first <= timestamp)
            {
                ans = store[key][mid].second;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
        
    }
};
