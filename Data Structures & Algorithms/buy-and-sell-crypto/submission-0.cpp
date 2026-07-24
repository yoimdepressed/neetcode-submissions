class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit  = 0;
        int mintillnow = INT_MAX;
        int maxtillnow = INT_MIN;
        for(int i = 0;i < prices.size();i++)
        {
            mintillnow = min(mintillnow,prices[i]);
            profit = max(profit, prices[i] - mintillnow);
        }
        return profit;
    }
};
