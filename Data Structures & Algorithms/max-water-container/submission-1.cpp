class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size()-1;
        int height = 0;
        int curr_height = 0;
        while(i < j)
        {
            if(heights[j] > heights[i])
            {
                curr_height = (j-i) * heights[i];
                i++;
            }
            else
            {
                curr_height = (j-i) * heights[j];
                j--;
            }
            height = max(height,curr_height);
            
        }
        return height;
    }
};
