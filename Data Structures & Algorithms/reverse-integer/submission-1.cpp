class Solution {
public:
    int reverse(int x) {
        int maxi = INT_MAX;
        int mini = INT_MIN;
        int ans = 0;
        while(x)
        {
            int rem = x%10;
            x = x/10;
            if(ans > maxi/10 || (ans == maxi/10 && rem > 7)) return 0;
            if(ans < mini/10 || (ans == mini/10 && rem < -8)) return 0;
            ans = ans*10 + rem;
        }
        return ans;
    }
};
