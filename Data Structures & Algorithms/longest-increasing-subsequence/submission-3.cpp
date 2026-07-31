class Solution {
public:
    int solve(vector<int>& nums,vector<vector<int>>& dp,int idx,int parent) {
        if(idx >= nums.size()) return 0;
        if(dp[idx][parent+1] != -1) return dp[idx][parent+1];
        int a = 0;
        int b = 0;
        if(parent == -1)
        {
            return dp[idx][parent+1] = max(1 + solve(nums,dp,idx+1,idx) , solve(nums,dp,idx+1,parent));
        }
        if(nums[idx] > nums[parent])
            a = 1 + solve(nums,dp,idx+1,idx);
        b = solve(nums,dp,idx+1,parent);
        return dp[idx][parent+1] = max(a,b);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums,dp,0,-1);
    }
};
