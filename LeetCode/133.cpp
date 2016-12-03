//
//  133.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    unordered_map<int, UndirectedGraphNode*> hash;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        if (hash.find(node->label) == hash.end()) {
            hash[node->label] = new UndirectedGraphNode(node->label);
            for (auto neighbor : node->neighbors) {
                hash[node->label]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return hash[node->label];
    }
};
