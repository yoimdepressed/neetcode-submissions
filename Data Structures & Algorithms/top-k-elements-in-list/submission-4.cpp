class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i = 0;i < nums.size();i++)
        {
            freq[nums[i]]++;
        }
        vector<vector<int>> bucket(nums.size()+1);
        for(auto it : freq)
        {
            bucket[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i = bucket.size()-1;i >= 0;i--)
        {
            if(k <= 0) break;
            for(int j = 0;j < bucket[i].size();j++)
            {
                if(k <= 0) break;
                ans.push_back(bucket[i][j]);
                k--;
            }
        }
        return ans;
    }
};
