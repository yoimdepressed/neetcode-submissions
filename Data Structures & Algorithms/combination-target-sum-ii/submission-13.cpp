class Solution {
public:
    set<vector<int>> ans;
    vector<int> temp;
    void solve(vector<int>& nums,int idx, int sum) {
        if(sum == 0)
        {
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
        else if(sum < 0 || idx == nums.size()) return;
        temp.push_back(nums[idx]);
        solve(nums,idx+1,sum-nums[idx]);
        while(idx + 1 < nums.size() && nums[idx] == nums[idx+1]) {
            idx++;
        }
        temp.pop_back();
        solve(nums,idx+1,sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,target);
        vector<vector<int>> comb;
        for(auto &v : ans)
        {
            comb.push_back(v);
        }
        return comb;
    }
};
