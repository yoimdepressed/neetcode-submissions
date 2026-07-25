class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> both(position.size());
        for(int i = 0;i < position.size();i++)
        {
            both[i].first = position[i];
            both[i].second = speed[i];
        }
        sort(both.begin(),both.end(),greater<pair<int,int>>());
        stack<double> st;
        int count = 0;
        vector<double> time(position.size());
        for(int i = 0;i < position.size();i++)
        {
            time[i] = (double)(target - both[i].first) / both[i].second;
        }
        int i = 0;
        while(i < position.size())
        {
            if(st.empty() || time[i] > st.top()) st.push(time[i]);
            
            i++;
        }
        return st.size();

    }
};
