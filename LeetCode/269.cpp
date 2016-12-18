//
//  269.cpp
//  LeetCode
//
//  Created by neal on 12/14/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string alienOrder(vector<string>& words) {
        string res;
        if (words.size() == 0) return res;
        if (words.size() == 1) return words[0];
        char graph[26][26] = {0};
        for (char& c : words[0]) {
            graph[c-'a'][c-'a'] = 1;
        }
        for (int i = 1; i < words.size(); i++) {
            for (char& c : words[i]) {
                graph[c-'a'][c-'a'] = 1;
            }
            setEdges(words[i-1], words[i], graph);
        }
        for (int i = 0; i < 26; i++) {
            int isIRootNode = graph[i][i];
            if (graph[i][i]) {
                for (int j = 0; j < 26; j++) {
                    if (j != i && graph[j][i]) {
                        isIRootNode = false;
                        break;
                    }
                }
            }
            if (isIRootNode) {
                string tmpRes = "";
                int mask = 0;
                if (dfs(tmpRes, mask, graph, i)) return "";
                else res += tmpRes;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (graph[i][i]) return "";
        }
        return res;
    }
    void setEdges(string& word1, string& word2, char graph[][26]) {
        int len = min((int) word1.length(), (int) word2.length());
        for (int i = 0; i < len; i++) {
            if (word1[i] != word2[i]) graph[word1[i]-'a'][word2[i]-'a'] = 1;
        }
    }
    bool dfs(string& path, int& mask, char graph[][26], int root) {
        if (mask & (1 << root)) { //visited, has circle;
            path = "";
            return true;
        }
        mask |= 1 << root; // visit root;
        for (int i = 0; i < 26; i++) {
            if (i != root && graph[root][i]) {
                if (dfs(path, mask, graph, i)) return true;
            }
        }
        graph[root][root] = false; // used;
        mask ^= (1 << root); // set visited = false;
        path = char ('a' + root) + path;
        return false; // no circle;
    }
};
