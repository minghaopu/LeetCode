//
//  279.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
private:
    unordered_map<int, int> hash;
public:
    int numSquares_TLE(int n) {
        for (int i = 0; i * i <= n; i++) {
            hash[i*i] = 1;
        }
        return helper(n);
    }
    int helper(int n) {
        if (hash.find(n) != hash.end()) return hash[n];
        if (n == 0) return 0;
        int minLen = INT_MAX, root = 1;
        while (root * root <= n) root++;
        for (int i = root - 1; i > 0; i--) {
            int rest = n - i * i;
            minLen = min(minLen, helper(rest) + 1);
        }
        hash[n] = minLen;
        return minLen;
    }
    bool isSquare(int n) {
        return pow((int)sqrt(n), 2) == n;
    }
    int numSquares(int n) {
        if (isSquare(n)) return 1;
        while ((n & 3) == 0) n >>= 2; // n % 4 == 0;
        if ((n & 7) == 7) return 4; // n % 8 == 7;
        int root = (int) sqrt(n);
        for (int i = 1; i <= root; i++ ) {
            if (isSquare(n - i * i)) return 2;
        }
        return 3;
    }
};
