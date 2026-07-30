class Solution {
public:
    vector<int> dp = vector<int>(101,-1);
    int solve(string& s,int idx) {
        if(idx >= s.size()) return 1;
        if(s[idx]-'0' == 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int a = 0;
        int c = 0;
        int d = 0;
        a = solve(s,idx+1);
        if(s[idx]-'0' == 1 && idx+1<s.size())
            c = solve(s,idx+2);
        if(s[idx]-'0' == 2 && idx+1<s.size() && s[idx+1]-'0' <= 6)
            d = solve(s,idx+2);
        return dp[idx] = a+c+d;
    }

    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        for(int i = 0;i < s.size();i++)
        {
            if(s[i]-'0' == 0 && (s[i-1]-'0' > 2 || s[i-1]-'0' == 0) ) return 0;
        }
        return solve(s,0);
    }
};
