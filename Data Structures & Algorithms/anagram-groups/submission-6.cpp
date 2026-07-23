class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(strs.size() == 0) return ans;
        if(strs.size() == 1)
        {
            ans.push_back(strs);
            return ans;
        }
        vector<string> s = strs;
        for(int i = 0;i < strs.size();i++)
        {
            sort(s[i].begin(),s[i].end());
        }
        unordered_map<string,vector<int>> map;
        for(int i = 0;i < strs.size();i++)
        {
            map[s[i]].push_back(i);
        }
        for(auto it : map)
        {
            vector<string> temp;
            for(int x : it.second)
            {
                temp.push_back(strs[x]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
