class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void recursion(vector<int>& nums,int idx) {
        if(idx == nums.size()) 
        {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[idx]);
        recursion(nums,idx+1);
        temp.pop_back();
        recursion(nums,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        recursion(nums,0);
        return ans;
    }
};
