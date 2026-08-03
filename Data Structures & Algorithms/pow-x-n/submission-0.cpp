class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0)
        {
            return myPow(1/x,-n);
        }
        if(n == 0) return 1.00000;
        
        double ans = 1;
        
        while(n > 0)
        {
            if(n % 2 == 1)
                ans *= x;
            x *= x;
            n = n/2;
        }
        return ans;
    }
};
