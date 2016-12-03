//
//  134.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int tank = 0;
        int begin = 0; // if begin can't reach i+1;, then every place between begin and i can't reach i+1; therefore begin = i+1;
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += (gas[i] - cost[i]);
            if (tank < 0) {
                begin = i+1;
                tank = 0;
            }
        }
        return totalGas < totalCost ? - 1 : begin;
    }
};
