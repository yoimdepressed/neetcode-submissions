class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int l = 0;
        int r = 0;
        int maxi = INT_MIN;
        while(r < nums.size() && l < nums.size())
        {
            sum += nums[r];
            r++;
            maxi = max(maxi , sum);
            while(sum < 0 && l < nums.size())
            {
                sum -= nums[l];
                l++;
            }
        }
        return maxi;
    }
};
