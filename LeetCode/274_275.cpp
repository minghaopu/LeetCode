//
//  274_275.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    // O(nlogn)
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        sort(citations.begin(), citations.end());
        int len = (int) citations.size();
        int left = 0, right = len - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (citations[mid] == len - mid) return len - mid;
            else if (citations[mid] < len - mid) left = mid + 1;
            else right = mid - 1;
        }
        return len - left;
    }
    // O(n)
    int hIndex_method2(vector<int>& citations) {
        if (citations.empty()) return 0;
        int len = (int) citations.size();
        vector<int> hash(len + 1, 0);
        for (int c : citations) {
            if (c >= len) hash[len]++;
            else hash[c]++;
        }
        int paper = 0;
        for (int i = len; i > -1; i--) {
            paper += hash[i];
            if (paper >= i) return i;
        }
        return 0;
    }
    // 275 already sort
    int hIndexII(vector<int>& citations) {
        if (citations.empty()) return 0;
        int len = (int)citations.size();
        
        int left = 0, right = len - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (citations[mid] == len - mid) return len - mid;
            else if (citations[mid] < len - mid) left = mid + 1;
            else right = mid - 1;
        }
        return len - left;
    }
};
