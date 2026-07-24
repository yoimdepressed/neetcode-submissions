class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        if(strs.empty()) return encoded;
        for(int i = 0;i < strs.size();i++)
        {
            int lengt = strs[i].length();
            string len = to_string(lengt);
            encoded += len;
            encoded += '#';
            encoded += strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        if(s.empty()) return decoded;
        int i = 0;
        while(i < s.size())
        {
            string temp;
            string integer;
            while(s[i] - '0' >= 0 && s[i] - '0' < 10 && s[i] != '#')
            {
                integer += s[i];
                i++;
            }
            int len = stoi(integer);
            i++;
            while(len > 0)
            {
                temp += s[i];
                i++;
                len--;
            }
            decoded.push_back(temp);
        }
        return decoded;
    }
};
