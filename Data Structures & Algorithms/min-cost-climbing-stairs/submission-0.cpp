class Solution {
public:
    vector<int> dp = vector<int>(101,-1);
    int solve(vector<int>& cost,int idx) {
        if(idx >= cost.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = min(solve(cost,idx+1) + cost[idx], solve(cost,idx+2) +     cost[idx]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int a = solve(cost,0);
        dp.resize(101,-1);
        int b = solve(cost,1);
        return min(a,b);
        
    }
};
