class Solution {
public:
    int solve(vector<vector<int>>& matrix,vector<vector<int>>& dp,int i,int j) {
        if(i >= matrix.size() || j >= matrix[0].size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int a = 1;
        int b = 1;
        int c = 1;
        int d = 1;
        if(i > 0 && matrix[i-1][j] > matrix[i][j])
            a = 1 + solve(matrix,dp,i-1,j);
        if(j > 0 && matrix[i][j-1] > matrix[i][j])
            b = 1 + solve(matrix,dp,i,j-1);
        if(i < matrix.size()-1 && matrix[i+1][j] > matrix[i][j])
            c = 1 + solve(matrix,dp,i+1,j);
        if(j < matrix[0].size()-1 && matrix[i][j+1] > matrix[i][j])
            d = 1 + solve(matrix,dp,i,j+1);
        return dp[i][j] = max({a,b,c,d});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int maxPath = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                maxPath = max(maxPath, solve(matrix, dp, i, j));
            }
        }
        
        return maxPath;
    }
};
