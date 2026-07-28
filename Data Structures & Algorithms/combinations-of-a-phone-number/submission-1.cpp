class Solution {
public:
    vector<string> ans;
    string temp;
    unordered_map<char,string> map = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void solve(string digits,int idx) {
        if(idx == digits.size())
        {
            ans.push_back(temp);
            return;
        }
        for(auto it : map[digits[idx]])
        {
            temp += it;
            solve(digits,idx+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        solve(digits,0);
        return ans;
    }
};
