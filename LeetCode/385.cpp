//
//  385.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s == "") return NestedInteger();
        if (s[0] != '[') return NestedInteger(stoi(s));
        stack<NestedInteger> st;
        for (int i = 0, j = 0; j < s.length(); j++) {
            if (s[j] == '[') {
                st.push(NestedInteger());
                i = j + 1;
            } else if (s[j] == ',' || s[j] == ']') {
                if (isdigit(s[j-1]))
                    st.top().add(NestedInteger(stoi(s.substr(i, j - i))));
                if (s[j] == ']' && st.size() > 1) {
                    NestedInteger cur = st.top();
                    st.pop();
                    st.top().add(cur);
                }
                i = j + 1;
            }
        }
        return st.top();
    }
};
