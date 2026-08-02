class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int count = 0;
        int x = 0;
        int y = 0;
        int z = 0;
        if(triplets.size() == 1)
        {
            if(triplets[0][0] == target[0] && triplets[0][1] == target[1] && triplets[0][2] == target[2]) return true;
            return false;
        }
        
        for(int i = 0;i < triplets.size();i++)
        {
            if(triplets[i][0] <= target[0] && triplets[i][1] <= target[1] &&      triplets[i][2] <= target[2])
            {
                x = max(x,triplets[i][0]);
                y = max(y,triplets[i][1]);
                z = max(z,triplets[i][2]);
                count++;
            }
        }
        if(count <= 1) return false;
        if(x == target[0] && y == target[1] && z == target[2]) return true;
        return false;
    }
};
