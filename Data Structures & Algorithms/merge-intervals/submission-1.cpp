class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int i = 0;
        while(i < intervals.size())
        {
            int x = intervals[i][0];
            int y = intervals[i][1];
            i++;
            while(i < intervals.size() && y >= intervals[i][0])
            {
                y = max(y, intervals[i][1]);
                i++;
            }
            ans.push_back({x,y});
            
        }
        return ans;
    }
};
