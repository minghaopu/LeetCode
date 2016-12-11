//
//  318.cpp
//  LeetCode
//
//  Created by roneil on 12/10/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int maxProduct(vector<string>& words) {
        map<int, int> hash;
        for (string word : words) {
            int mask = 0;
            for (char c : word) {
                mask |= (1 << (c-'a'));
            }
            hash[mask] = max(hash[mask], (int) word.length());
        }
        int len = 0;
        for (auto it = hash.begin(); it != hash.end(); it++) {
            for (auto it2 = hash.begin(); it2 != hash.end(); it2++) {
                if ((it->first & it2->first) == 0) {
                    len = max(len, it->second * it2->second);
                }
            }
        }
        return len;
    }
};
