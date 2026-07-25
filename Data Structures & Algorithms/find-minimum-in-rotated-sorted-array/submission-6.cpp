class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;
        if(nums.size() == 1) return nums[0];
        if(nums[r] < nums[r-1]) return nums[r];
        if(nums[0] < nums[r]) return nums[0];
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if((mid+1 < nums.size() && nums[mid] < nums[mid+1]) && (mid-1 >= 0 && nums[mid] < nums[mid-1]))
            {
                return nums[mid];
            }
            if(nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return nums[0];
    }
    
};
