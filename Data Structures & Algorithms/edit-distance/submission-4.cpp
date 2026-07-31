class Solution {
public:
    int solve(string word1, string word2,vector<vector<int>>& dp,int idx1,int idx2)
    {
        if(idx1 >= word1.size()) return word2.size()-idx2;
        if(idx2 >= word2.size()) return word1.size()-idx1;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(word1[idx1] == word2[idx2])
        {
            return dp[idx1][idx2] = solve(word1,word2,dp,idx1+1,idx2+1);
        }
        else
        {
            return dp[idx1][idx2] = 1 + min({solve(word1,word2,dp,idx1+1,idx2+1) , solve(word1,word2,dp,idx1,idx2+1) , solve(word1,word2,dp,idx1+1,idx2)});
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return solve(word1,word2,dp,0,0);
    }
};
