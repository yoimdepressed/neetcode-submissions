class Solution {
public:
    bool isPalindrome(string s) {
        string fin;
        for(int i = 0;i < s.size();i++)
        {
            if((s[i] - 'a' >=0 && s[i] - 'a' < 26) || (s[i] - 'A' >=0 && s[i] - 'A' < 26)
            || (s[i] - '0' >= 0 && s[i] - '0' < 10))
            {
                if(s[i] >= 'A' && s[i] <= 'Z')
                    fin += s[i] - 'A' + 'a';
                else
                    fin += s[i];
            }
        }
        int i = 0;
        int j = fin.size()-1;
        while(i < j)
        {
            if(fin[i] != fin[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
