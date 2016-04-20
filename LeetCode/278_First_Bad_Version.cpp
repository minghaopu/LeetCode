//
//  278_First_Bad_Version.cpp
//  LeetCode
//
//  Created by roneil on 16/4/20.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"



class Solution {
private:
    int n;
    vector<bool> vb;
public:
    bool isBadVersion(int version) {
        return vb[version];
    };
    Solution (int num) {
        n = num;
        bool value = false;
        for (int i = 0; i<1000; i++) {
            if (i == 2) {
                value = true;
            }
            vb.push_back(value);
        }
    }
    int firstBadVersion() {
        int low = 1;
        int high = n;
        int mid;
        bool value;
        while (low <= high) {
            mid = low + (high - low)/2;
            value = isBadVersion(mid);
            if (value) {
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
        
    }
};