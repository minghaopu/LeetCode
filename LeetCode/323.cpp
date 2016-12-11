//
//  323.cpp
//  LeetCode
//
//  Created by roneil on 12/10/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int *parent = new int[n];
        iota(parent, parent + n, 0);
        for (auto edge : edges) {
            int node1 = find(parent, edge.first), node2 = find(parent, edge.second);
            parent[node1] = node2;
            n -= node1 != node2;
        }
        return n;
    }
    int find(int parent[], int node) {
        return parent[node] == node ? node : find(parent, parent[node]);
    }
};
