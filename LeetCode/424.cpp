//
//  424.cpp
//  LeetCode
//
//  Created by neal on 12/18/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int characterReplacement(string s, int k) {
        int cache[26] = {0};
        int start = 0, res = 0, maxCount = 0;
        for (int end = 0; end < s.length(); end++) {
            cache[s[end] - 'A']++;
            if (maxCount < cache[s[end] - 'A']) maxCount = cache[s[end] - 'A'];
            while (end - start - maxCount + 1 > k) {
                cache[s[start++] - 'A']--;
                for (int i = 0; i < 26; i++) {
                    if (maxCount < cache[i]) maxCount = cache[i];
                }
            }
            res = max(res, end - start + 1);
        }
        return res;
    }
};
