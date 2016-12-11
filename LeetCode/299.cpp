//
//  299.cpp
//  LeetCode
//
//  Created by roneil on 12/9/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string getHint(string secret, string guess) {
        int smap[10] = {0}, gmap[10] = {0};
        int bull = 0, cow = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) bull++;
            else {
                smap[secret[i]-'0']++;
                gmap[guess[i]-'0']++;
            }
        }
        for (int i = 0; i < 10; i++) {
            if (gmap[i] != 0 && smap[i] != 0) cow += min(smap[i], gmap[i]);
        }
        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};
