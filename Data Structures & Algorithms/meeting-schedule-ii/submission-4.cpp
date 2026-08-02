/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const Interval& a,const Interval &b)
        {
            return a.start < b.start;
        });
        if(intervals.size() == 0) return 0;
        int count = 1;
        vector<int> rooms(intervals.size(),-1);
        rooms[0] = intervals[0].end;
        for(int i = 0;i < (int)intervals.size()-1;i++)
        {
            int temp = 0;
            while(temp < count && intervals[i+1].start < rooms[temp])
            {
                temp++;
            }

            if(temp == count)
            {
                count++;
            }
            rooms[temp] = intervals[i+1].end;
            
            
        }
        return count;
    }
};
