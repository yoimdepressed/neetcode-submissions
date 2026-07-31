class Solution {
public:
    bool find(vector<int>& nums,int sum,int idx,vector<vector<int>>& dp) {
        if(sum == 0) return true;
        if(idx >= nums.size() || sum < 0) return false;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        bool a = false;
        if(nums[idx] <= sum)
        {
            a = find(nums,sum-nums[idx],idx+1,dp) || find(nums,sum,idx+1,dp);
        }
        else a = find(nums,sum,idx+1,dp);
        return dp[idx][sum] = a ? 1 : 0;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0;i < nums.size();i++)
        {
            sum += nums[i];
        }
        if(sum % 2 == 1) return false;
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,-1));
        return find(nums,sum/2,0,dp);
    }
};
