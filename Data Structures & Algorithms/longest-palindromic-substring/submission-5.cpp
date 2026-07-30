class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxi = 1;
        int a = 0;
        int b = 0;
        for(int i = 0;i < n;i++)
        {
            int l = i;
            int r = i;
            int curr = 1;
            while(l-1 >= 0 && r+1 < n)
            {
                if(s[l-1] == s[r+1]) curr += 2;
                else break;
                l--;
                r++;
            }
            if(curr > maxi)
            {
                maxi = curr;
                a = l;
                b = r;
            }
        }
        for(int i = 0;i < n-1;i++)
        {
            int l = i;
            int r = i+1;
            int curr = 1;
            if(s[l] == s[r])
            {
                curr++;
                while(l-1 >= 0 && r+1 < n)
                {
                    if(s[l-1] == s[r+1]) curr += 2;
                    else break;
                    l--;
                    r++;
                }
                if(curr > maxi)
                {
                    maxi = curr;
                    a = l;
                    b = r;
                }
            }
        }
        string lafoot;
        lafoot = s.substr(a,b-a+1);
        return lafoot;
    }
};
