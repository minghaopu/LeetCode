//
//  464_CanIWin.cpp
//  LeetCode
//
//  Created by neal on 6/18/17.
//  Copyright © 2017 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
private:
    unordered_map<unsigned int, bool> cache;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false;
        unsigned int used = (1 << maxChoosableInteger) - 1;
        return helper(desiredTotal, used, maxChoosableInteger);
    }
    bool helper(int target, unsigned int used, int size) {
        if (cache.find(used) != cache.end()) return cache[used];
        if (target - 1 < size && used > (1 << target - 1)) {
            cache[used] = true;
            return true;
        }
        int bit = 1;
        for (int i = 0; i < size; i++, bit <<= 1) {
            if ((used & bit) == 0) continue;
            used ^= bit;
            if (!helper(target - i - 1, used, size)) {
                used |= bit;
                cache[used] = true;
                return true;
            }
            used |= bit;
        }
        cache[used] = false;
        return false;
    }
};
