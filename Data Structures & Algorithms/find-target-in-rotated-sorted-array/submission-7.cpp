class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r])
            {
                l = mid+1;
            }
            else r = mid-1;
        }
        if(nums[l] == target) return l;
        int left = l;
        int right = nums.size()-1;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid-1;
            else left = mid+1;
        }
        left = 0;
        right = l-1;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }
};
