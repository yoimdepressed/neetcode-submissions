class Solution {
public:
    int solve(vector<int>& coins,vector<vector<int>>& dp, int amount,int idx) {
        if(amount == 0) return 1;
        if(idx >= coins.size() || amount < 0) return 0;
        if(dp[idx][amount] != -1) return dp[idx][amount];
        if(coins[idx] <= amount)
        {
            return dp[idx][amount] = solve(coins,dp,amount-coins[idx],idx) + solve(coins,dp,amount,idx+1);
        }
        else return dp[idx][amount] = solve(coins,dp,amount,idx+1);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return solve(coins,dp,amount,0);
    }
};
