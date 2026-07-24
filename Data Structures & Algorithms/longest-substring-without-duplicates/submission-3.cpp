class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        unordered_map<int,int> freq;
        int curr_count = 0;
        int count = 0;
        while(i < s.size() && j < s.size())
        {
            while(freq.count(s[i]) > 0)
            {
                freq[s[j]]--;
                if(freq[s[j]] == 0) freq.erase(s[j]);
                j++;
                curr_count--;
            }
            freq[s[i]]++;
            curr_count++;
            i++;
            
            count = max(curr_count,count);
        }
        return count;
    }
};
