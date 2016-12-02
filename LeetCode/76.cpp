//
//  76.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string minWindow(string s, string t) {
        int map[128] = {0};
        for (char c : t) map[c]++;
        int i = 0, j = 0, n = (int) s.length(), count = (int) t.length(), head = 0, len = n + 1;
        while (j < n) {
            if (map[s[j++]]-- > 0) count--;
            while (count == 0) {
                if (j - i < len) {
                    len = j - i;
                    head = i;
                }
                if (map[s[i++]]++ == 0) count++;
            }
        }
        return len == n + 1 ? "" : s.substr(head, len);
    }
};
