class Twitter {
public:
    int timer = 0;
    unordered_map<int,vector<pair<int,int>>> user;
    unordered_map<int,unordered_set<int>> follower;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        user[userId].push_back({timer,tweetId});
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<vector<int>> ans;
        for(auto it : follower[userId])
        {
            for(auto it2 : user[it])
            {
                ans.push_back({it2.first, it2.second});
            }
        }
        for(auto it : user[userId])
        {
            ans.push_back({it.first, it.second});
        }
        sort(ans.rbegin(), ans.rend());
        vector<int> recent;
        int mini = min((int)ans.size(),10);
        for(int i = 0;i < mini;i++)
        {
            recent.push_back(ans[i][1]);
        }
        return recent;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follower[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};
