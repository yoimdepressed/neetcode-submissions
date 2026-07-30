class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int maxi = 1;
        int a = 0;
        int b = 0;
        int count = 0;
        for(int i = 0;i < n;i++)
        {
            int l = i;
            int r = i;
            count++;
            while(l-1 >= 0 && r+1 < n)
            {
                if(s[l-1] == s[r+1]) count++;
                else break;
                l--;
                r++;
            }
        }
        for(int i = 0;i < n-1;i++)
        {
            int l = i;
            int r = i+1;
            int curr = 1;
            if(s[l] == s[r])
            {
                count++;
                while(l-1 >= 0 && r+1 < n)
                {
                    if(s[l-1] == s[r+1]) count++;
                    else break;
                    l--;
                    r++;
                }
            }
        }
        return count;
    }
};
