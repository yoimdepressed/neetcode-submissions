class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map;
        if(nums.size() == 0) return 0;
        for(int i = 0;i < nums.size();i++)
        {
            map[nums[i]]++;
        }
        int count = 1;
        for(int i = 0;i < nums.size();i++)
        {
            int curr_count = 1;
            if(map.count(nums[i]-1) == 0)
            {
                int temp = nums[i]+1;
                while(map.count(temp) > 0)
                {
                    curr_count++;
                    temp++;
                }
            }
            count = max(count,curr_count);
        }
        return count;
    }
};
