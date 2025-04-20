class Twitter {
public:

    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> allTweets;
        priority_queue<pair<int, int>> pq;

        for(auto following : follows[userId]) {
            for(auto tweet : tweets[following]) {
                allTweets.push_back(tweet);
            }
        }

        for(auto tweet : tweets[userId]) {
            allTweets.push_back(tweet);
        }

        for (auto t : allTweets) pq.push(t);

        vector<int> feed;
        for (int i = 0; i < 10 && !pq.empty(); i++) {
            feed.push_back(pq.top().second);
            pq.pop();
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */