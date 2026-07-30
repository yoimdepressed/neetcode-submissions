class Solution {
public:
    vector<long long> dp = vector<long long>(46,-1);
    long long climbStairs(long long n) {
        if(n <= 0) return dp[0] = 0;
        if(n == 1) return dp[1] = 1;
        if(n == 2) return dp[2] = 2;
        if(dp[n] != -1) return dp[n];
        return dp[n] = climbStairs(n-2) + climbStairs(n-1);
    }
};
