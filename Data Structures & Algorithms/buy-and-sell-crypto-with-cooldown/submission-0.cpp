class Solution {
public:
    int solve(vector<int>& prices,vector<vector<int>>& dp,int idx,int flag) {
        if(idx >= prices.size()) return 0;
        if(dp[idx][flag] != -1) return dp[idx][flag];
        if(flag == 0)
        {
            return dp[idx][flag] = max(solve(prices,dp,idx+1,1) - prices[idx] , solve(prices,dp,idx+1,0));
        }
        if(flag == 1)
        {
            return dp[idx][flag] = max(solve(prices,dp,idx+2,0) + prices[idx] , solve(prices,dp,idx+1,1));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        int flag = 0;
        return solve(prices,dp,0,flag);
    }
};
