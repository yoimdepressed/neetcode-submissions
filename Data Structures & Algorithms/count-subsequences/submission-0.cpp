class Solution {
public:
    int solve(string s, string t,int idx1,int idx2,vector<vector<int>>& dp) {
        if(idx2 >= t.size()) return 1;
        if(idx1 >= s.size()) return 0;
        if(idx2 == t.size()-1 && s[idx1] == t[idx2]) return 1 + solve(s,t,idx1+1,idx2,dp);
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s[idx1] == t[idx2])
        {
            return dp[idx1][idx2] = solve(s,t,idx1+1,idx2,dp) + solve(s,t,idx1+1,idx2+1,dp);
        }
        else return dp[idx1][idx2] = solve(s,t,idx1+1,idx2,dp);
    }
    int numDistinct(string s, string t) {
        if(s.size() < t.size()) return 0;
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
        return solve(s,t,0,0,dp);
    }
};
