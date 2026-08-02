class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26,-1);
        for(int i = 0;i < s.size();i++)
        {
            freq[s[i]-'a'] = i;
        }
        int count = 0;
        int l = 0;
        int r = 0;
        vector<int> ans;
        for(int i = 0;i < s.size();i++)
        {
            r = freq[s[i]-'a'];
            l = i;
            while(l <= r)
            {
                r = max(r,freq[s[l]-'a']);
                l++;
            }
            ans.push_back(r-i+1);
            i = r;
        }
        return ans;
    }
};
