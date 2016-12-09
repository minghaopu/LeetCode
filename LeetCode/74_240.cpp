//
//  74.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    // use same method;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
//        if (matrix.empty() || matrix[0].empty()) return false;
//        int m = (int)matrix.size(), n = (int)matrix[0].size();
//        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
//        int low = 0, high = m-1;
//        while (low <= high) {
//            int mid = (low + high) / 2;
//            if (matrix[mid][0] == target) return true;
//            else if (matrix[mid][0] < target) low = mid + 1;
//            else high = mid - 1;
//        }
//        int row = low - 1;
//        low = 0;
//        high = n-1;
//        while (low <= high) {
//            int mid = (low + high) / 2;
//            if (matrix[row][mid] == target) return true;
//            else if (matrix[row][mid] < target) low = mid + 1;
//            else high = mid - 1;
//        }
//        return false;
        if (matrix.empty() || matrix[0].empty()) return false;
        int i = 0, j = (int)matrix[0].size() - 1;
        while (i < matrix.size() && j > - 1) {
            int t = matrix[i][j];
            if (t > target) j--;
            else if (t < target) i++;
            else return true;
        }
        return false;
    }
    bool searchMatrix_II(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int i = 0, j = (int)matrix[0].size() - 1;
        while (i < matrix.size() && j > - 1) {
            int t = matrix[i][j];
            if (t > target) j--;
            else if (t < target) i++;
            else return true;
        }
        return false;
    }
};
