//
//  71.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string simplifyPath(string path) {
        string res = "", token;
        stringstream ss (path);
        vector<string> tokens;
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") continue;
            else if (token == "..") {
                if (!tokens.empty()) tokens.pop_back();
            } else tokens.push_back(token);
        }
        if (tokens.empty()) return "/";
        for (string token : tokens) res += '/' + token;
        return res;
    }
};
