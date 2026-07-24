class Solution {
public:
    void twoSum(int idx,vector<int>& numbers, int target,vector<vector<int>>& ans) {
        int i = idx+1;
        int j = numbers.size()-1;
        
        while(i < j)
        {
            if(numbers[i] + numbers[j] == target)
            {
                vector<int> temp;
                temp.push_back(numbers[idx]);
                temp.push_back(numbers[i]);
                temp.push_back(numbers[j]);
                sort(temp.begin(),temp.end());

                ans.push_back(temp);
                i++;
                j--;
                while(i < j && numbers[i] == numbers[i-1]) i++;
                while(i < j && numbers[j] == numbers[j+1]) j--;
                
            }
            else if(numbers[i] + numbers[j] > target)
            {
                j--;
            }
            else i++;
        }
        return;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n;i++)
        {   
            if(i>0 && nums[i]==nums[i-1]) continue;
            twoSum(i,nums,-nums[i],ans);
        }
        return ans;
    }
};
