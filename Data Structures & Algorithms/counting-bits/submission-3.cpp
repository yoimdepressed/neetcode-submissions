class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0;i <= n;i++)
        {
            int cnt = 0;
            int temp = i;
            while(temp)
            {
                if(temp & 1) cnt++;
                temp >>= 1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
