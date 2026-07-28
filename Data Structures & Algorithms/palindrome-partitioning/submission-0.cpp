class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    
    bool check(int l, int r, string& s) {
        while(l <= r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    
    void solve(string& s, int idx) {
        if(idx == s.size()) {
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx; i < s.size(); i++) {
            if(check(idx, i, s)) {
                temp.push_back(s.substr(idx, i - idx + 1)); 
                
                solve(s, i + 1);
                temp.pop_back(); 
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        solve(s, 0); 
        return ans;
    }
};