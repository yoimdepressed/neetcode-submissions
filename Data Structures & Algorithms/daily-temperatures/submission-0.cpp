class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> arr(n, 0);
        int i = 0;
        stack<pair<int,int>> st;
        while(i < n)
        {
            while(!st.empty() && st.top().first < temperatures[i])
            {
                int curr = st.top().second;
                arr[curr] = i - curr;
                st.pop();
            }
            
                st.push({temperatures[i],i});
            
            i++;
        }
        return arr;
    }
};
