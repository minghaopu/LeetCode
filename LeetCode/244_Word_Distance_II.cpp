//
//  244_Word_Distance_II.cpp
//  LeetCode
//
//  Created by roneil on 11/16/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class WordDistance {
    unordered_map<string, vector<int>> cache;
public:
    WordDistance(vector<string>& words) {
        int l = words.size();
        for (int i = 0; i < l; i++) {
            cache[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int i = 0, j = 0;
        int dis = INT_MAX;
        while (i < cache[word1].size() && j < cache[word2].size()) {
            dis = min(abs(cache[word1][i] - cache[word2][j]), dis);
            if (cache[word1][i] < cache[word2][j]) i++; // this word1 is before word2, move to next word1 which will nearer word2
            else j++;
        }
        return dis;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
