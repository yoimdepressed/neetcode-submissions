class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int maxi = INT_MIN;
        int ind = -1;
        int gass = 0;
        int costs = 0;
        for(int i = 0;i < gas.size();i++)
        {
            gass += gas[i];
            costs += cost[i];
        }
        if(gass < costs) return -1;
        int total = 0;
        int idx = 0;
        for(int i = 0;i < gas.size();i++)
        {
            total += gas[i]-cost[i];
            if(total < 0) 
            {
                idx = i+1;
                total = 0;
            }
        }
        
        return idx;
    }
};
