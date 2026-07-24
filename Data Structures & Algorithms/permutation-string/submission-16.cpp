class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int n = s1.size();
        int i = 0;
        int j = 0;
        vector<int> arr1(26,0);
        vector<int> arr2(26,0);
        if(s1 == s2) return true;
        if(n == 1)
        {
            char ch = s1[0];
            for(int i = 0;i < s2.size();i++)
            {
                if(s2[i] == ch) return true;
            }
            return false;
        }
        for(int i = 0;i < n;i++)
        {
            arr1[s1[i]-'a']++;
        }
        while(j < s2.size())
        {
            if(j+1 <= n)
            {
                arr2[s2[j]-'a']++;
                j++;
                if(arr1 == arr2) return true;
            }
            else
            {
                arr2[s2[i]-'a']--;
                arr2[s2[j]-'a']++;
                if(arr1 == arr2) return true;
                j++;
                i++;
            }
        }
        return false;
    }
};
