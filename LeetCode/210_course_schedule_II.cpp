//
//  210_course_schedule_II.cpp
//  LeetCode
//
//  Created by roneil on 11/14/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    vector<bool> visited;
    vector<bool> color;
    vector<set<int>> graph;
    vector<int> result;
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (prerequisites.empty()) {
            for (int i = 0; i < numCourses; i++) result.push_back(i);
            return result;
        }
        visited.assign(numCourses, false);
        color.assign(numCourses, false);
        graph.assign(numCourses, set<int> ());
        for (auto it = prerequisites.begin(); it != prerequisites.end(); it++) {
            graph[it->first].insert(it->second);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (color[i]) continue;
            if (dfs(i)) return {};
        }
        return result;
    }
    bool dfs(int node) {
        color[node] = true;
        visited[node] = true;
        for (auto neighbor : graph[node]) {
            if (!color[neighbor]) {
                if(dfs(neighbor)) return true;
            }
            if (visited[neighbor]) return true;
        }
        visited[node] = false;
        result.push_back(node);
        return false;
    }
};
