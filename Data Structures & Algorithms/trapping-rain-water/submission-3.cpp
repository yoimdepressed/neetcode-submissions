class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        vector<int> leftmax(height.size(),-1);
        
        int maxi = INT_MIN;
        for(int i = 0;i < height.size();i++)
        {
            maxi = max(maxi,height[i]);
            leftmax[i] = maxi;
            
        }
        vector<int> rightmax(height.size(),-1);
        maxi = INT_MIN;
        for(int i = height.size()-1;i >= 0;i--)
        {
            maxi = max(maxi,height[i]);
            rightmax[i] = maxi;
        }
        int sum = 0;
        for(int i = 0;i < height.size();i++)
        {
            if(leftmax[i] != -1 && rightmax[i] != -1)
                sum += min(leftmax[i],rightmax[i]) - height[i];
        }
        return sum;
    }
};
