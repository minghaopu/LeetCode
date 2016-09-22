//
//  170.cpp
//  LeetCode
//
//  Created by roneil on 9/15/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class TwoSum {
private:
    unordered_map<int, int> map;
public:
    
    // Add the number to an internal data structure.
    void add(int number) {
        map[number]++;
    }
    
    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            int i = it->first;
            int j = value - i;
            if ((i == j && it->second > 1) || (i != j && map.find(j) != map.end())) {
                return true;
            }
        }
        return false;
    }
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
