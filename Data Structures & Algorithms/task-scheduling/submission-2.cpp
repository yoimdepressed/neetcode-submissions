class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> map;
        for(int i = 0;i < tasks.size();i++)
        {
            map[tasks[i] - 'A']++;
        }
        priority_queue<int> pq;
        for(auto it : map)
        {
            pq.push(it.second);
        }
        int ans = 0;
        while(!pq.empty())
        {
            int counter = 0;
            vector<int> temp;
            int s = pq.size();
            while(!pq.empty() && counter < n+1)
            {
                if(pq.top()-1 > 0)
                    temp.push_back(pq.top()-1);
                pq.pop();
                counter++;
            }
            if(temp.empty()) ans += counter;
            else ans += n + 1;
            for(int i = 0;i < temp.size();i++) pq.push(temp[i]);
        }
        return ans;
    }
};
