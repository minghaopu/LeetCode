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
    
    struct Node {
        Node* parent;
        double val = 0.0;
        Node (double val): val(val), parent(this) {};
    };
    unordered_map<string, Node*> map;
    
    Node* findParent(Node* node) {
        if (node->parent == node) return node;
        node->parent = findParent(node->parent);
        return node->parent;
    };
    void unionNodes(Node* node1, Node* node2, double num) {
        Node* parent1 = findParent(node1);
        Node* parent2 = findParent(node2);
        double ratio = node2->val * num / node1->val;
        for (auto it = map.begin(); it != map.end(); it++) {
            if (findParent(it->second) == parent1) {
                it->second->val *= ratio;
            }
        }
        parent1->parent = parent2;
    }
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res;
        for (int i = 0; i < equations.size(); i++) {
            string s1 = equations[i].first;
            string s2 = equations[i].second;
            if (map.count(s1) == 0 && map.count(s2) == 0) {
                map[s1] = new Node(values[i]);
                map[s2] = new Node(1);
                map[s1]->parent = map[s2];
            } else if (map.count(s1) == 0) {
                map[s1] = new Node(map[s2]->val * values[i]);
                map[s1]->parent = map[s2];
            } else if (map.count(s2) == 0) {
                map[s2] = new Node(map[s1]->val / values[i]);
                map[s2]->parent = map[s1];
            } else {
                unionNodes(map[s1],map[s2],values[i]);
            }
        }
        for (auto query : queries) {
            if (map.count(query.first) == 0 || map.count(query.second) == 0 || findParent(map[query.first]) != findParent(map[query.second])) {
                res.push_back(-1);
            } else {
                res.push_back(map[query.first]->val / map[query.second]->val);
            }
        }
        return res;
    }
};
