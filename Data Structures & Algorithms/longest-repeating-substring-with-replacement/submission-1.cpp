class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> freq;
        int l = 0;
        int r = 0;
        int max_freq = 0;
        int maxi = 0;
        char ch = s[0];
        while(r < s.size())
        {
            freq[s[r]]++;
            max_freq = max(max_freq,freq[s[r]]);
            while(r-l+1-max_freq > k)
            {
                freq[s[l]]--;
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
