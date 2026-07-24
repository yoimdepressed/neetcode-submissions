class Solution {
public:
    bool check(string s,string t,vector<int>& freqt,vector<int>& freqs)
    {
        for(int i = 0;i < t.size();i++)
        {
            if(freqs[t[i]] < freqt[t[i]]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(s == t) return s;
        int n = s.size();
        int m = t.size();
        string ans;
        if(n < m) return ans;
        int i = 0;
        int j = 0;
        vector<int> freqt(128,0);
        for(int k = 0;k < m;k++)
        {
            freqt[t[k]]++;
        }
        vector<int> freqs(128,0);
        // for(int k = 0;k < n;k++)
        // {
        //     freqs[s[k]]++;
        // }
        int mini = INT_MAX;
        int a = 0;
        int b = n-1;
        while(i < n && j < n)
        {
            int flag = 0;
            freqs[s[j]]++;
            j++;
            while(check(s,t,freqt,freqs))
            {
                freqs[s[i]]--;
                i++;
                flag = 1;
            }
            if(flag == 1)
            {
                i--;
                freqs[s[i]]++;
                if(j - i < mini)
                {
                    mini = j - i;
                    a = i;
                    b = j;
                }
            }
            
        }
        if(mini == INT_MAX) return ans;
        ans += s.substr(a,b-a);
        return ans;

    }
};
