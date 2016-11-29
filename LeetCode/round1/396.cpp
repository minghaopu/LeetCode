//
//  396.cpp
//  LeetCode
//
//  Created by roneil on 9/20/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long int f = 0;
        long long int sum = 0;
        int size = A.size();
        for (int i = 0; i < size; i++) {
            f += A[i] * i;
            sum += A[i];
        }
        long long int result = f;
        for (int i = 1; i < size; i++) {
            f += sum - A[size - i] * size;
            result = max(f, result);
        }
        return result;
    }
};
