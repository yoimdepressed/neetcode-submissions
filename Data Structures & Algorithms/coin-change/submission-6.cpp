class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& coins, int amount,int idx)
    {
        if(amount == 0) return 0;
        if(idx >= coins.size() || amount < 0) return 1e9;
        if(dp[idx][amount] != -1) return dp[idx][amount];
        return dp[idx][amount] = min(1 + solve(coins,amount-coins[idx],idx) , solve(coins,amount,idx+1));
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(coins.size(), vector<int>(amount + 1, -1));
        int ans = solve(coins,amount,0);
        if(ans >= 1e9) return -1;
        return ans;

    }
};
