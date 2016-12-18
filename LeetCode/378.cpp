//
//  378.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return -1;
        int n = (int)matrix.size();
        auto comp = [](const pair<int, pair<int, int>> a, const pair<int, pair<int, int>> b) {return a.first > b.first;};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(comp)> q(comp);
        for (int i = 0; i < min(n, k); i++) q.push({matrix[i][0], make_pair(i,0)});
        while (k-- > 1) {
            int i = q.top().second.first;
            int j = q.top().second.second;
            q.pop();
            if (j + 1 < n) q.push({matrix[i][j+1], make_pair(i, j + 1)});
        }
        return q.top().first;
    }
};
class SolutionII {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return -1;
        int n = (int)matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1], count, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            count = 0;
            for (int i = 0; i < n; i++) {
                auto row = matrix[i];
                count += upper_bound(row.begin(), row.end(), mid) - row.begin();
            }
            if (count < k) left = mid + 1;
            else right = mid;
        }
        return left;
        
    }
};
