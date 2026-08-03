class Solution {
public:
    int sumsquares(int n) {
        int sum = 0;
        while(n != 0)
        {
            sum += (n%10)*(n%10);
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        vector<int> visited(244,0);
        while(n != 1)
        {
            n = sumsquares(n);
            if(!visited[n])
                visited[n] = 1;
            else if(visited[n] == 1) return false;
            if(n == 1) return true;
        }
        return true;
    }
};
