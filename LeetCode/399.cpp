//
//  399.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    unordered_map<string, vector<string>> graph;
    map<pair<string, string>, double> edges;
    unordered_set<string> visited;
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        if (equations.empty() || values.empty() || queries.empty()) return {};
        int n = (int) equations.size();
        for (int i = 0; i < n; i++) {
            pair<string, string> edge = equations[i];
            double val = values[i];
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
            edges.insert({edge, val});
            edges.insert({make_pair(edge.second, edge.first), 1 / val});
        }
        vector<double> res;
        for (auto q : queries) {
            string node1 = q.first, node2 = q.second;
            if (graph.find(node1) == graph.end() || graph.find(node2) == graph.end()) res.push_back(-1.0);
            else if (node1 == node2) res.push_back(1.0);
            else if (edges.find(q) != edges.end()) res.push_back(edges[q]);
            else {
                double val = 1.0;
                if (find(node1, node2, val)) res.push_back(val);
                else res.push_back(-1.0);
            }
            visited.clear();
        }
        return res;
    }
    bool find(string node, string end, double& value) {
        if (node == end) return true;
        visited.insert(node);
        for (string neighbor : graph[node]) {
            if (neighbor == end) {
                value *= edges[make_pair(node, end)];
                return true;
            }
            if (visited.count(neighbor) == 0) {
                double v = 1.0;
                if (find(neighbor, end, v)) {
                    value *= v * edges[make_pair(node, neighbor)];
                    edges.insert({make_pair(node, end), value});
                    return true;
                }
            }
        }
        visited.erase(node);
        return false;
    }
};
