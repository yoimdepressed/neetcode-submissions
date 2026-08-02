class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        int k = groupSize;
        if(n % k != 0) return false;
        sort(hand.begin(),hand.end());
        map<int,int> freq;
        for(int i = 0;i < n;i++)
        {
            freq[hand[i]]++;
        }
        while(freq.size() != 0)
        {
            
                int num = freq.begin()->first;
                freq[num]--;
                if(freq[num] == 0) freq.erase(num);
                for(int i = 0;i < k-1;i++)
                {
                    num++;
                    if(freq.find(num) == freq.end()) return false;
                    freq[num]--;
                    if(freq[num] == 0) freq.erase(num);
                }
        }
        return true;
    }
};
