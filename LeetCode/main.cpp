//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//
#include "Header.h"
class Solution {
private:
    bool hasCircle(vector<unordered_set<int>>& graph, char visit[], char path[], int node, vector<int>& res) {
        if (visit[node]) return false;
        visit[node] = 1;
        path[node] = 1;
        for (int neighbor : graph[node]) {
            if (path[neighbor] || hasCircle(graph, visit, path, neighbor, res)) return true;
        }
        path[node] = 0;
        res.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if (prerequisites.empty()) {
            res.resize(numCourses);
            for (int i = 0; i < numCourses; i++) res[i] = i;
            return res;
        }
        
        vector<unordered_set<int>> graph;
        for (auto p : prerequisites) {
            graph[p.second].insert(p.first);
        }
        
        char visit[numCourses];
        fill_n(&visit[0], numCourses, 0);
        char path[numCourses];
        fill_n(&path[0], numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (!visit[i] && hasCircle(graph, visit, path, i, res)) return {};
        }
        return res;
    }
};
//#include "79.cpp"
//#include "Medium.cpp"
//#include "312. Burst Balloons.cpp"
//#include "Hard.cpp"
//#include "421. Maximum XOR of Two Numbers in an Array.cpp"
//void test(int amount) {
//
//    int *dp = (int*) malloc (amount * sizeof(int));
//    memset(dp, amount, sizeof(int) * (amount));
//    for (int i = 0; i < amount; i++) cout<<dp[i]<<endl;
//}
vector<int> getRecommendedTweets(vector<tuple<int, int>> followGraph_edges,
                                 vector <tuple<int, int>> likeGraph_edges,
                                 int targetUser,
                                 int minLikeThreshold) {
    unordered_set<int> targetUserFollowing;
    unordered_map<int, vector<int>> usersLikes;
    unordered_map<int, int> tweets;
    vector<int> recommendTweets;
    for (auto t : followGraph_edges) {
        int user = get<0>(t), following = get<1>(t);
        if (user == targetUser) {
            targetUserFollowing.insert(following);
        }
    }
    for (auto t : likeGraph_edges) {
        int user = get<0>(t), tweet = get<1>(t);
        if (targetUserFollowing.find(user) != targetUserFollowing.end()) {
            tweets[tweet]++;
        }
    }
    for (auto it = tweets.begin(); it != tweets.end(); it++) {
        recommendTweets.push_back(it->second);
    }
    return recommendTweets;
}

int main(int argc, const char * argv[]) {

    return 0;
}
