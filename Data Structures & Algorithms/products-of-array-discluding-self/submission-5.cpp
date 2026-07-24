class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(),1);
        vector<int> suffix(nums.size(),1);
        int n = nums.size();
        int product = 1;
        prefix[0] = 1;
        for(int i = 1;i < n;i++)
        {
            product = product*nums[i-1];
            prefix[i] = product;
        }
        suffix[nums.size()-1] = 1;
        product = 1;
        for(int i = nums.size()-2;i >= 0;i--)
        {
            product = product*nums[i+1];
            suffix[i] = product;
        }
        vector<int> ans(n);
        for(int i = 0;i < nums.size();i++)
        {
            ans[i] = (prefix[i] * suffix[i]);
        }
        return ans;
    }
};
