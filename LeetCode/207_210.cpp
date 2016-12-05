
//
//  207.cpp
//  LeetCode
//
//  Created by roneil on 12/5/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    bool hasCircle(int node, vector<bool>& visited, vector<bool>& onpath, vector<unordered_set<int>>& graph) {
        if (visited[node]) return false;
        visited[node] = true;
        onpath[node] = true;
        for (int neighbor : graph[node]) {
            if (onpath[neighbor] || hasCircle(neighbor, visited, onpath, graph)) return true;
        }
        onpath[node] = false;
        return false;
    }
    bool hasCircle_findOrder(int node, vector<bool>& visited, vector<bool>& onpath, vector<unordered_set<int>>& graph, vector<int>& res) {
        if (visited[node]) return false;
        visited[node] = true;
        onpath[node] = true;
        for (int neighbor : graph[node]) {
            if (onpath[neighbor] || hasCircle_findOrder(neighbor, visited, onpath, graph, res)) return true;
        }
        onpath[node] = false;
        res.push_back(node);
        return false;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto p : prerequisites) {
            graph[p.second].insert(p.first);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> onpath(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && hasCircle(i, visited, onpath, graph)) return false;
        }
        return true;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if (prerequisites.empty()) {
            for (int i = 0; i < numCourses; i++) res.push_back(i);
            return res;
        }
        vector<unordered_set<int>> graph(numCourses);
        for (auto p : prerequisites) {
            graph[p.first].insert(p.second);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> onpath(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && hasCircle_findOrder(i, visited, onpath, graph, res)) return {};
        }
        return res;
    }
};
