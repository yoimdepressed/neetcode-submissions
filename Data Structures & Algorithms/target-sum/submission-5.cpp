class Solution {
public:
    int solve(vector<int>& nums,int sum,vector<vector<int>>& dp,int idx) {
        if(idx >= nums.size())
        {
            if (sum == 0) return 1;
            else return 0;
        }
        if(sum < 0) return 0;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        if(nums[idx] <= sum)
            return dp[idx][sum] = solve(nums,sum-nums[idx],dp,idx+1) + solve(nums,sum,dp,idx+1);
        else 
            return dp[idx][sum] = solve(nums,sum,dp,idx+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0;i < nums.size();i++) sum += nums[i];
        if (sum < abs(target) || (sum + target) % 2 != 0) {
            return 0;
        }
        sum = (sum+target)/2;
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum + 1,-1));
        return solve(nums,sum,dp,0);
    }
};
