//
//  261.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        int *parent = new int[n];
        iota(parent, parent + n, 0);
        for (pair<int, int> edge : edges) {
            int node1 = find(parent, edge.first);
            int node2 = find(parent, edge.second);
            if (node1 == node2) return false; // has circle
            parent[node1] = node2;
        }
        return edges.size() == n - 1;
    }
    int find(int parent[], int node) {
        if (parent[node] == node) return node;
        return find(parent, parent[node]);
    }
};
