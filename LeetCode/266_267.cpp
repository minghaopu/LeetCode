//
//  266_267.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    // 266;
    bool canPermutePalindrome(string s) {
        int map[128] = {0};
        for (char c : s) map[c]++;
        int hasOdd = 0;
        for (int n : map) {
            if (n & 1) {
                if (++hasOdd >= 2) return false;
            }
        }
        return true;
    }
    //267
    vector<string> generatePalindromes(string s) {
        int map[128] = {0};
        for (char c : s) map[c]++;
        int hasOdd = 0, oddIndex = 0, len = (int) s.length();
        for (int i = 0; i < 128; i++) {
            if (map[i] & 1) {
                oddIndex = i;
                if (++hasOdd >= 2) return {};
            }
        }
        vector<string> res;
        if (hasOdd == 0) helper(res, "", len, map);
        else {
            map[oddIndex]--;
            string path = "";
            path += (char) oddIndex;
            helper(res, path, len - 1, map);
        }
        return res;
    }
    void helper(vector<string>& res, string path, int rest, int map[]) {
        if (rest == 0) {
            res.push_back(path);
            return;
        }
        string tmp;
        for (int i = 0; i < 128; i++) {
            if (map[i] > 0) {
                tmp = char(i) + path + char(i);
                map[i] -= 2;
                helper(res, tmp, rest - 2, map);
                map[i] += 2;
            }
        }
    }
};
