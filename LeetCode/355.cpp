//
//  355.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Twitter {
private:
    int timestamp;
    struct Tweet{
        int id;
        int time;
        Tweet* next;
        Tweet(int id, int timestamp) : id(id), time(timestamp), next(NULL) {};
    };
    struct User {
        int id;
        set<int> followed;
        Tweet* thead;
        User(int id) : id(id), thead(NULL) {};
        void follow(int id) {
            followed.insert(id);
        };
        void unfollow(int id) {
            followed.erase(id);
        }
        void post(int tweetId, int timestamp) {
            Tweet *p = new Tweet(tweetId, timestamp);
            p->next = thead;
            thead = p;
        }
    };
    unordered_map<int, User*> users;
public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (users.find(userId) == users.end()) {
            users[userId] = new User(userId);
        }
        users[userId]->post(tweetId, timestamp);
        timestamp++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if (users.find(userId) == users.end()) return {};
        auto followed = users[userId]->followed;
        auto cmp = [](const Tweet* a, const Tweet* b) {
            return a->time < b->time;
        };
        priority_queue<Tweet*, vector<Tweet*>, decltype(cmp)> q(cmp);
        for (auto it = followed.begin(); it != followed.end(); it++) {
            int count = 0;
            Tweet *p = users[*it]->thead;
            while (count < 10 && p != NULL) {
                q.push(p);
                p = p->next;
                count++;
            }
        }
        int count = 0;
        Tweet* p = users[userId]->thead;
        while (count < 10 && p != NULL) {
            q.push(p);
            p = p->next;
            count++;
        }
        vector<int> res;
        for (int i = 0; i < 10 && !q.empty(); i++) {
            res.push_back(q.top()->id);
            q.pop();
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (users.find(followerId) == users.end()) {
            users[followerId] = new User(followerId);
        }
        if (users.find(followeeId) == users.end()) {
            users[followeeId] = new User(followeeId);
        }
        if (followerId == followeeId) return;
        users[followerId]->follow(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (users.find(followerId) == users.end()) return;
        if (followerId == followeeId) return;
        users[followerId]->unfollow(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
