//
//  133_clone_graph.cpp
//  LeetCode
//
//  Created by roneil on 10/16/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
private:
    unordered_map<int, UndirectedGraphNode*> hash;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return node;
        if (hash.find(node->label) == hash.end()) {
            hash[node->label] = new UndirectedGraphNode(node->label);
            for (int i = 0; i < node->neighbors.size(); i++) {
                (hash[node->label]->neighbors).push_back(cloneGraph(node->neighbors[i]));
            }
        }
        return hash[node->label];
    }
};
