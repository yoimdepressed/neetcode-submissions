class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int l = 1;
        int r = nums[0];
        int count = 1;
        while(r < nums.size()-1 && l < nums.size())
        {
            int far = r;
            while(l <= r)
            {
                far = max(far,l + nums[l]);
                l++;
            }
            r = far;
            count++;
        }
        return count;
    }
};
