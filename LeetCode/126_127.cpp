//
//  126_127.cpp
//  LeetCode
//
//  Created by roneil on 12/2/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    vector<vector<string>> res;
    unordered_map<string, vector<string>> map;
    unordered_map<string, int> visit;
    vector<string> path;
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {// Trie tree bfs traverse
        queue<string> Q;
        Q.push(beginWord);
        int size, l = (int)beginWord.length(), len = 2;
        while (!Q.empty()) {
            size = (int)Q.size();
            while (size--) {
                beginWord = Q.front();
                Q.pop();
                for (int i = 0; i < l; i++) {
                    string tmp = beginWord;
                    for (int j = 0; j < 26; j++) {
                        tmp[i] = 'a' + j;
                        if (tmp == endWord) return len;
                        if (wordList.find(tmp) == wordList.end()) continue;
                        Q.push(tmp);
                        wordList.erase(tmp);
                    }
                }
            }
            len++;
        }
        return 0;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        queue<string> Q;
        Q.push(beginWord);
        visit[beginWord] = 0;
        int len = (int)beginWord.length();
        while (!Q.empty()) {// bfs create map;
            string s = Q.front();
            Q.pop();
            if (s == endWord) break;
            int step = visit[s];
            vector<string> neighbors;
            for (int i = 0; i < len; i++) {
                string tmp = s;
                for (int j = 0; j < 26; j++) {
                    tmp[i] = 'a' + j;
                    if (tmp == s || wordList.find(tmp) == wordList.end()) continue;
                    if (visit.find(tmp) == visit.end()) {
                        Q.push(tmp);
                        visit[tmp] = step + 1;
                    }
                    neighbors.push_back(tmp);
                }
            }
            map[s] = neighbors;
        }
        path.push_back(beginWord);
        dfs(beginWord, endWord); //dfs create path
        return res;
    }
    void dfs(string now, string end) {
        if (now == end) res.push_back(path);
        else {
            vector<string> neighbors = map[now];
            int curLevel = visit[now];
            for (string next : neighbors) {
                if (visit[next] != curLevel + 1) continue;
                path.push_back(next);
                dfs(next, end);
                path.pop_back();
            }
        }
    }
};
