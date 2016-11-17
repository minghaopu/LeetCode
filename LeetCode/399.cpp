//
//  399.cpp
//  LeetCode
//
//  Created by roneil on 11/16/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    unordered_map<string, int> hash;
    vector<vector<double>> matrix;
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        makeGraph(equations, values);
        vector<double> res;
        for (int i = 0; i < queries.size(); i++) {
            string node1 = queries[i].first;
            string node2 = queries[i].second;
            if (hash.find(node1) != hash.end() && hash.find(node2) != hash.end()) {
                res.push_back(matrix[hash[node1]][hash[node2]]);
            }
            else res.push_back(-1.0);
        }
        return res;
    }
    void makeGraph(vector<pair<string, string>> equations, vector<double>& values) {
        int count = 0;
        unordered_map<int, set<int>> edges;
        for (int i = 0; i < equations.size(); i++) {
            string node1 = equations[i].first;
            string node2 = equations[i].second;
            
            if (hash.find(node1) == hash.end()) {
                hash[node1] = count;
                count++;
            }
            if (hash.find(node2) == hash.end()) {
                hash[node2] = count;
                count++;
            }
            if (edges.find(hash[node1]) == edges.end()) edges[hash[node1]] = set<int> ();
            edges[hash[node1]].insert(hash[node2]);
            edges[hash[node2]].insert(hash[node1]);
        }
        matrix.assign(count, vector<double> (count, -1.0));
        for (int i = 0; i < equations.size(); i++) {
            int node1 = hash[equations[i].first];
            int node2 = hash[equations[i].second];
            matrix[node1][node2] = values[i];
            if (matrix[node2][node1] == -1) matrix[node2][node1] = values[i] == 0 ? INT_MAX:1/values[i];
        }
        for (int i = 0; i < count; i++) {
            matrix[i][i] = 1.0;
        }
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                if (matrix[i][j] == -1) {
                    dfs(edges, i, j);
                }
            }
        }
    }
    double dfs(unordered_map<int, set<int>>& edges, int start, int end) {
        if (edges[start].find(end) != edges[start].end()) return matrix[start][end];
        auto nodes = edges[start];
        for (auto it = nodes.begin(); it != nodes.end(); it++) {
            int next = *it;
            double val = dfs(edges, next, end);
            if (val != -1) {
                matrix[start][end] = matrix[start][next] * val;
                matrix[end][start] = val  == 0 ? INT_MAX: 1 / matrix[start][end];
                edges[start].insert(end);
                return start;
            }
        }
        return -1.0;
    }
};
