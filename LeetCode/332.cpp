
//
//  332.cpp
//  LeetCode
//
//  Created by roneil on 12/10/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> graph;
        for (auto ticket : tickets) {
            graph[ticket.first].insert(ticket.second);
        }
        vector<string> path;
        dfs("JFK", path, graph);
        reverse(path.begin(), path.end());
        return path;
    }
    void dfs(string start, vector<string>& path, unordered_map<string, multiset<string>>& graph) {
        while (graph[start].size()) {
            string next = *graph[start].begin();
            graph[start].erase(graph[start].begin());
            dfs(next, path, graph);
        }
        path.push_back(start);
    }
};
