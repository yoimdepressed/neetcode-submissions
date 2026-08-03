class CountSquares {
public:
    map<pair<int,int>,int> freq;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        freq[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int cnt = 0;
        for(int i = 0;i <= 1000;i++)
        {
            if(freq.count({i,y}) > 0 && i != x)
            {
                int len = abs(i-x);
                if(freq.count({i,y + len}) > 0)
                {
                    if(freq.count({x,y + len}) > 0)
                    {
                        int b = freq[{x,y+len}];
                        int c = freq[{i,y}];
                        int d = freq[{i,y+len}];
                        cnt += b*c*d;
                    }
                }
                else if(freq.count({i,y - len}) > 0)
                {
                    if(freq.count({x,y - len}) > 0)
                    {
                        int b = freq[{x,y-len}];
                        int c = freq[{i,y}];
                        int d = freq[{i,y-len}];
                        cnt += b*c*d;
                    }
                }
            }
        }
        return cnt;
    }
};
