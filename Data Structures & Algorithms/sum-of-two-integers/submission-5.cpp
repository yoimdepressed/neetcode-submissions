class Solution {
public:
    int getSum(int a, int b) {
        int ans= 0;
        int carry = 0;
        unsigned int ua = a;
        unsigned int ub = b;
        int i = 0;
        while(ua || ub || carry && i < 32)
        {
            int x = ua&1;
            int y = ub&1;
            int curr_bit = x^y^carry;
            ans = ans | (curr_bit << i++);
            carry = (x&y) | (x&carry) | (y&carry);
            ua >>= 1;
            ub >>= 1;
        }
        return ans;

    }
};
