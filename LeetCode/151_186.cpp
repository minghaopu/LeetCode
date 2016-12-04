//
//  151_186.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    void reverseWords(string &s) {
        stack<string> st;
        int i, j;
        for (i = 0, j = 0; j < s.length(); j++) {
            if (s[j] == ' ') {
                if (i != j) st.push(s.substr(i, j-i));
                i = j + 1;
            }
        }
        if (i != j) st.push(s.substr(i, j-i));
        string ns = "";
        while (!st.empty()) {
            ns += st.top() + " ";
            st.pop();
        }
        if (ns != "") s = ns.substr(0, ns.length() - 1);
        else s = "";
    }
    void reverseWords_II(string &s) { // constant space
        int start = 0;
        bool hasSpace = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                hasSpace = true;
                reverse(s.begin() + start, s.begin() + i);
                start = i+1;
            }
        }
        if (hasSpace) {
            if (start < s.length()) reverse(s.begin() + start, s.end());
            reverse(s.begin(), s.end());
        }
    }
};
