class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(vector<int>& nums,int idx, int sum) {
        if(sum == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(idx == nums.size())
        {
            return;
        }
        else if(sum < 0) return;
        temp.push_back(nums[idx]);
        solve(nums,idx,sum-nums[idx]);
        temp.pop_back();
        solve(nums,idx+1,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(nums,0,target);
        return ans;
    }
};
