class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> map;
        for(int i = 0;i < s.size();i++)
        {
            map[s[i]-'a']++;
        }
        unordered_map<int,int> map2;
        for(int i = 0;i < t.size();i++)
        {
            if(map[t[i] - 'a'] == 0 || map.find(t[i]-'a') == map.end())return false;
            map[t[i]-'a']--;
        }
        for(int i = 0;i < 26;i++)
        {
            if(map[i] > 0) return false;
        }
        return true;
    }
};
