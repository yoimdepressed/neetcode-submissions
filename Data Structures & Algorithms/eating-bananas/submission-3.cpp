class Solution {
public:
    bool caneat(int k,vector<int>& piles, int h) {
        int sum = 0;
        for(int i = 0;i < piles.size();i++)
        {
            if(piles[i] < k) sum++;
            else if(piles[i] % k == 0)
            {
                sum += piles[i] / k;
            }
            else if(piles[i] > k)
            {
                sum += (piles[i] / k) + 1;
            }
        }
        if(sum <= h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = piles[0];
        for(int i = 1;i < piles.size();i++)
        {
            maxi = max(maxi,piles[i]);
        }
        int l = 1;
        int r = maxi;
        int mini = maxi;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(caneat(mid,piles,h))
            {
                mini = mid;
                r = mid-1;
            }
            else l = mid + 1;
        }
        return mini;
    }
};
