//
//  260.cpp
//  LeetCode
//
//  Created by roneil on 2016/11/28.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string alienOrder(vector<string>& words) {
        string res;
        if (words.size() == 0) return res;
        if (words.size() == 1) return words[0];
        bool graph[26][26] = {false};
        for (char c : words[0]) {
            graph[c-'a'][c-'a'] = true;
        }
        for (int i = 1; i < words.size(); i++) {
            for (char c : words[i]) {
                graph[c-'a'][c-'a'] = true;
            }
            findEdges(words[i-1], words[i], graph);
        }
        for (int i = 0; i < 26; i++) {
            bool rootNode = graph[i][i];
            if (graph[i][i]) {
                for (int j = 0; j < 26; j++) {
                    if (j != i && graph[j][i]) {
                        rootNode = false;
                        break;
                    }
                }
            }
            if (rootNode) {
                string tmpRes = "";
                int mask = 0;
                // vector<bool> tmpMask(26, false);
                if (dfs(tmpRes, mask, graph, i)) return "";
                else res += tmpRes;
            }
            
        }
        for (int i = 0; i < 26; i++) {
            if (graph[i][i]) return "";
        }
        return res;
    }
    void findEdges(string& word1, string& word2, bool graph[][26]) {
        int tmpLen = min(int(word1.length()), int(word2.length()));
        for (int i = 0; i < tmpLen; i++) {
            if (word1[i] != word2[i]) {
                graph[word1[i] - 'a'][word2[i] - 'a'] = true;
            }
        }
    }
    bool dfs(string& path, int& mask, bool graph[][26], int root) {
        if (mask & (1 << root)) {
            path = "";
            return true;
        }
        mask |= 1 << root;
        for (int i = 0; i < 26; i++) {
            if (i != root && graph[root][i]) {
                if (dfs(path, mask, graph, i)) return true;
            }
        }
        graph[root][root] = false;
        mask ^= 1 << root;
        path = char('a' + root) + path;
        return false;
    }
};
