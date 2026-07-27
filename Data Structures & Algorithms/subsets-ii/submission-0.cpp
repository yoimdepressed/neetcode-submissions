class Solution {
public:
    set<vector<int>> ans;
    vector<int> temp;
    void solve(vector<int>& nums,int idx) {
        if(idx == nums.size())
        {
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(nums,idx+1);
        temp.pop_back();
        solve(nums,idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums,0);
        vector<vector<int>> comb;
        for(auto &v : ans)
        {
            comb.push_back(v);
        }
        return comb;
    }
};
