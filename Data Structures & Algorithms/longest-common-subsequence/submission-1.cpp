class Solution {
public:
    int solve(string& s1,string& s2,int idx1,int idx2,vector<vector<int>>& dp)
    {
        if(idx1 < 0 || idx2 < 0) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s1[idx1] == s2[idx2])
        {
            return dp[idx1][idx2] = 1 + solve(s1, s2, idx1-1, idx2-1, dp);
        }
        else
        {
            return dp[idx1][idx2] = max(solve(s1, s2, idx1, idx2-1, dp), solve(s1, s2, idx1-1, idx2, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size() - 1;
        int n = text2.size() - 1;
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        
        return solve(text1, text2, m, n, dp);
    }
};
