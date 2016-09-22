//
//  243.cpp
//  LeetCode
//
//  Created by roneil on 9/15/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "header.h"
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int dis = words.size(), i = 0, index1 = -words.size(), index2 = -words.size();
        while (i < words.size()) {
            if (words[i] == word1) {
                index1 = i;
                dis = min(dis, index1 - index2);
            } else if (words[i] == word2) {
                index2 = i;
                dis = min(dis, index2 - index1);
            }
            i++;
        }
        return (index1 < 0 || index2 < 0) ? -1 : dis;
    }
};
