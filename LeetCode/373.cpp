//
//  373.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty()) return {};
        vector<pair<int, int>> res;
        int m = (int) nums1.size(), n = (int) nums2.size();
        k = min(m * n, k);
        vector<int> indexes (m, 0);
        while (k--) {
            int tmpIndex = 0;
            int tmpSum = INT_MAX;
            for (int i = 0; i < m; i++) {
                if (indexes[i] < n && tmpSum >= nums2[indexes[i]] + nums1[i]) {
                    tmpIndex = i;
                    tmpSum = nums2[indexes[i]] + nums1[i];
                }
            }
            res.push_back({nums1[tmpIndex], nums2[indexes[tmpIndex]]});
            indexes[tmpIndex]++;
        }
        return res;
    }
};
class SolutionII {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty()) return {};
        vector<pair<int, int>> res;
        int m = (int) nums1.size(), n = (int) nums2.size();
        auto comp = [](const pair<int, int> a, const pair<int, int> b){ return a.first + a.second < b.first + b.second;};
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> q(comp);
        int qsz = 0;
        for (int i = 0; i < min(m, k); i++) {
            for (int j = 0; j < min(n, k); j++) {
                if (qsz < k) {
                    q.push({nums1[i], nums2[j]});
                    qsz++;
                } else if (qsz == k && nums1[i] + nums2[j] < q.top().first + q.top().second) {
                    q.push({nums1[i], nums2[j]});
                    q.pop();
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};
