//
//  204.cpp
//  LeetCode
//
//  Created by roneil on 12/5/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<int> prime(n, 1);
        prime[0] = 0;
        prime[1] = 0;
        for (int i = 1; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = 0;
                }
            }
        }
        return (int)count(prime.begin(), prime.end(), 1);
    }
};
