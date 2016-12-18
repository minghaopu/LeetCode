//
//  388.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int lengthLongestPath(string input) {
        if (input == "") return 0;
        stringstream ss(input);
        string token;
        stack<int> preLength;
        int level = 0, res = 0, tmpLength = 0, count = 0;
        while (getline(ss, token, '\n')) {
            count = 0;
            while (token[count] == '\t') count++;
            while (level > count) {
                preLength.pop();
                level--;
            }
            if (token.find_last_of('.') != string::npos) {
                // file
                tmpLength = (int)token.length();
                if (level > 0) tmpLength += preLength.top();
                res = max(res, tmpLength);
            } else {
                // directory
                if (level > 0) preLength.push((int)preLength.top() + (int)token.length() - count);
                else preLength.push((int)token.length());
                level++;
            }
        }
        return res;
    }
};
