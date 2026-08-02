class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int x = newInterval[0];
        int y = newInterval[1];
        int i = 0;
        int flag = 0;
        vector<vector<int>> ans;
        
        // FIX 1: Put i < intervals.size() FIRST to prevent Out-Of-Bounds (OOB) error
        while(i < intervals.size() && intervals[i][1] < x)
        {
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        
        // greater than all
        // FIX 2: Check i == intervals.size(), not size()-1 (also handles empty intervals array)
        if(i == intervals.size())
        {
            ans.push_back({x,y});
            return ans;
        }
        
        // no overlap
        else if(intervals[i][0] > y)
        {
            ans.push_back({x,y});
            while(i < intervals.size())
            {
                ans.push_back({intervals[i][0],intervals[i][1]});
                i++;
            }
            return ans;
        }
        
        // overlap case 1
        else if(intervals[i][0] > x)
        {
            // FIX 3: Add OOB check to this while loop
            while(i < intervals.size() && intervals[i][1] < y)
            {
                i++;
            }
            
            // FIX 4: Handle case where the new interval swallowed the rest of the array
            if (i == intervals.size()) {
                ans.push_back({x, y});
                return ans;
            }
            
            if(intervals[i][0] > y)
            {
                ans.push_back({x,y});
                while(i < intervals.size())
                {
                    ans.push_back({intervals[i][0],intervals[i][1]});
                    i++;
                }
                return ans;
            }
            else if(intervals[i][0] <= y)
            {
                ans.push_back({x,intervals[i][1]});
                i++;
                while(i < intervals.size())
                {
                    ans.push_back({intervals[i][0],intervals[i][1]});
                    i++;
                }
                return ans;
            }
        }
        
        // overlap case 2
        else if(intervals[i][0] <= x)
        {
            // FIX 5: Save the starting point! The while loop changes 'i', 
            // so we can't use intervals[i][0] for the start of our merged interval later.
            int startVal = intervals[i][0]; 
            
            // FIX 3: Add OOB check
            while(i < intervals.size() && intervals[i][1] < y)
            {
                i++;
            }
            
            // FIX 4: Handle case where the new interval swallowed the rest of the array
            if (i == intervals.size()) {
                ans.push_back({startVal, y});
                return ans;
            }
            
            if(intervals[i][0] > y)
            {
                // FIX 5: use startVal instead of intervals[i][0]
                ans.push_back({startVal,y});
                while(i < intervals.size())
                {
                    ans.push_back({intervals[i][0],intervals[i][1]});
                    i++;
                }
                return ans;
            }
            else if(intervals[i][0] <= y)
            {
                // FIX 5: use startVal instead of intervals[i][0]
                ans.push_back({startVal,intervals[i][1]});
                i++;
                while(i < intervals.size())
                {
                    ans.push_back({intervals[i][0],intervals[i][1]});
                    i++;
                }
                return ans;
            }
        }

        // FIX 6: Ensure function always returns something at the end to prevent compiler warnings
        return ans; 
    }
};