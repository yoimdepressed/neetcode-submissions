class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        int i = 0;
        while(i < k)
        {
            pq.push({nums[i],i});
            i++;
        }
        ans.push_back(pq.top().first);
        for(i = k;i < nums.size();i++)
        {
            pq.push({nums[i],i});
            if(pq.top().second > i-k)
            {
                ans.push_back(pq.top().first);
            }
            else
            {
                while(pq.top().second <= i-k) pq.pop();
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};
