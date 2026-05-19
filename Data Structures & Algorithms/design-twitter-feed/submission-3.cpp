class Twitter {
private:
    int time;
    // userId -> list of tweets {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;
    // followerId -> set of followees
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Declaring a MIN-HEAP. The pair with the smallest 'time' will be at the top.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rec;

        // 1. Push user's own tweets
        for (auto &tweet : tweets[userId]) {
            rec.push(tweet);
            if (rec.size() > 10) {
                rec.pop(); // Removes the oldest tweet in the heap
            }
        }

        // 2. Push followees' tweets
        for (int followee : following[userId]) {
            for (auto &tweet : tweets[followee]) {
                rec.push(tweet);
                if (rec.size() > 10) {
                    rec.pop(); // Removes the oldest tweet in the heap
                }
            }
        }

        // 3. Extract the remaining 10 newest tweets
        // (Note: They will come out from oldest to newest)
        vector<int> feed;
        while (!rec.empty()) {
            feed.push_back(rec.top().second);
            rec.pop();
        }
        
        // 4. Reverse the vector so it is ordered from newest to oldest
        reverse(feed.begin(), feed.end());
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};