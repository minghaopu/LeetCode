//
//  223.cpp
//  LeetCode
//
//  Created by roneil on 12/6/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int overlap;
        if (A >= G || C <= E || B >= H || D <= F) overlap = 0;
        else overlap = (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
        return (C - A) * (D - B) + (G - E) * (H - F) - overlap;
    }
};
