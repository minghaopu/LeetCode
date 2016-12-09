//
//  243_244_245.cpp
//  LeetCode
//
//  Created by roneil on 12/7/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
//    243. Shortest Word Distance I // word1 != word2;
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int len = (int) words.size(), minLen = INT_MAX, w1 = -len, w2 = -len;
        for (int i = 0; i < len; i++) {
            if (word1 == words[i]) {
                w1 = i;
                minLen = min(w1 - w2, minLen);
            }  else if (word2 == words[i]) {
                w2 = i;
                minLen = min(w2 - w1, minLen);
            }
        }
        return minLen;
    }
//    245. Shortest Word Distance III // word1 may == word2
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int len = (int) words.size(), w1 = -len, w2 = -len, minLen = INT_MAX;
        for (int i = 0; i < len; i++) {
            if (word1 == words[i]) {
                if (word1 == word2) minLen = min(i - w1, minLen);
                else minLen = min(i - w2, minLen);
                w1 = i;
            } else if (word2 == words[i]) {
                w2 = i;
                minLen = min(i - w1, minLen);
            }
        }
        return minLen;
    }
};
//244. Shortest Word Distance II // call many times
class WordDistance {
private:
    unordered_map<string, vector<int>> hash;
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) hash[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        int len = INT_MAX;
        for (int i1 : hash[word1]) {
            for (int i2 : hash[word2]) len = min(abs(i1-i2), len);
        }
        return len;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
