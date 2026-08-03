class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int target = (n)*(n+1)/2;
        int sum = 0;
        for(auto it : nums)
        {
            sum += it;
        }
        return target - sum;
    }
};
