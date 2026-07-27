class Solution {
public:
    void bit(int j,vector<int>& temp) {
        if(j == 0)
        {
            temp.push_back(0);
            return;
        }
        while(j > 0)
        {
            int remainder = j%2;
            j = j/2;
            temp.push_back(remainder);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        for(int j = 0;j < 1 << n;j++)
        {
            vector<int> temp;
            bit(j,temp);
            vector<int> temp2;
            for(int i = 0;i < temp.size();i++)
            {
                if(temp[i] == 1)
                {
                    temp2.push_back(nums[i]);
                }
            }
            ans.push_back(temp2);
        }
        return ans;
            
        
    }
};
