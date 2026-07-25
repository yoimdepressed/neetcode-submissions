class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // FIX 1: Proper recursive call syntax
        if(nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1); 
        }
        
        int x = nums1.size();
        int y = nums2.size();
        
        // FIX 2: Add +1 so the left half gets the extra element for odd lengths
        int half = (x + y + 1) / 2; 
        
        int l = 0;
        int r = x;
        
        while(l <= r)
        {
            int part1 = (l+r)/2;
            int part2 = half - part1;
            
            // FIX 3: Add 'int' to declare variables
            int max_left_1;
            if(part1 == 0) max_left_1 = INT_MIN;
            else max_left_1 = nums1[part1-1];
            
            int min_right_1;
            if(part1 == x) min_right_1 = INT_MAX;
            else min_right_1 = nums1[part1];

            int max_left_2;
            if(part2 == 0) max_left_2 = INT_MIN;
            else max_left_2 = nums2[part2-1];
            
            int min_right_2;
            // FIX 4: Changed 'x' to 'y' because part2 belongs to nums2
            if(part2 == y) min_right_2 = INT_MAX; 
            else min_right_2 = nums2[part2];

            if(max_left_1 <= min_right_2 && max_left_2 <= min_right_1)
            {
                if((x+y)%2 == 0)
                {
                    // FIX 5: Use min_right (not min_left), wrap in parentheses, divide by 2.0
                    return (max(max_left_1, max_left_2) + min(min_right_1, min_right_2)) / 2.0; 
                }
                else
                    return max(max_left_1, max_left_2);
            }
            else if(max_left_1 > min_right_2)
            {
                r = part1 - 1;
            }
            else l = part1 + 1;
        }
        return 0.0;
    }
};