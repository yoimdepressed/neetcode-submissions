class Solution {
public:
    vector<int> dp = vector<int>(101,-1);
    int solve(vector<int>& nums, int idx)
    {
        if(idx >= nums.size()-1) return 0;
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = max(solve(nums,idx+1),solve(nums,idx+2)+nums[idx]);
    }
    int solve2(vector<int>& nums, int idx)
    {
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = max(solve2(nums,idx+1),solve2(nums,idx+2)+nums[idx]);
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int a = solve(nums,0);
        fill(dp.begin(), dp.end(), -1);
        int b = solve2(nums,1);
        return max(a,b);
    }
};
