//
//  339.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    //339 bfs
    int depthSum(vector<NestedInteger>& nestedList) {
        if (nestedList.empty()) return 0;
        queue<NestedInteger> q;
        for (auto item : nestedList) q.push(item);
        int sum = 0, level = 0, size = 0;
        while (!q.empty()) {
            level++;
            size = (int)q.size();
            while (size--) {
                NestedInteger i = q.front();
                q.pop();
                if (i.isInteger()) sum += i.getInteger() * level;
                else {
                    for (auto item : i.getList()) q.push(item);
                }
            }
        }
        return sum;
    }
    // 339 dfs
    int depthSum_dfs(vector<NestedInteger>& nestedList) {
        return dfs(nestedList, 1);
    }
    int dfs(vector<NestedInteger> nestedList, int level) {
        int sum = 0;
        for (auto item : nestedList) {
            if (item.isInteger()) sum += level * item.getInteger();
            else {
                sum += dfs(item.getList(), level+1);
            }
        }
        return sum;
    }
    // 364 bfs
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        if (nestedList.empty()) return 0;
        queue<NestedInteger> q;
        vector<int> cache(1, 0);
        for (auto item : nestedList) q.push(item);
        int sum = 0, level = 0, size = 0;
        while (!q.empty()) {
            size = (int)q.size();
            while (size--) {
                NestedInteger i = q.front();
                q.pop();
                if (i.isInteger()) cache[level] += i.getInteger();
                else {
                    for (auto item : i.getList()) q.push(item);
                }
            }
            cache.push_back(0);
            level++;
        }
        for (int i = 0; i < level; i++) {
            sum += (level - i) * cache[i];
        }
        return sum;
    }
    int depthSumInverse_dfs(vector<NestedInteger>& nestedList) {
        if (nestedList.empty()) return 0;
        int sum = 0;
        vector<int> cache(1, 0);
        dfs(nestedList, cache, 1);
        int level = (int)cache.size();
        for (int i = 0; i < level; i++) {
            sum += (level - i) * cache[i];
        }
        return sum;
    }
    void dfs(const vector<NestedInteger>& nestedList, vector<int>& cache, int level) {
        if (cache.size() < level) cache.resize(level);
        for (auto item : nestedList) {
            if (item.isInteger()) cache[level-1] += item.getInteger();
            else {
                dfs(item.getList(), cache, level+1);
            }
        }
    }
};
