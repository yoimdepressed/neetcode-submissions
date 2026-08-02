class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int count = 0;
        int i = 0;
        while(i < intervals.size())
        {
            int x = intervals[i][0];
            int y = intervals[i][1];
            i++;
            while(i < intervals.size() && y > intervals[i][0])
            {
                y = min(y, intervals[i][1]);
                i++;
                count++;
            }
            ans.push_back({x,y});
            
        }
        return count;
    }
};
