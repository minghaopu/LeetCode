//
//  249_Group_Shifted_Strings.cpp
//  LeetCode
//
//  Created by roneil on 16/4/28.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"

//class Solution {
//public:
//    vector<vector<string>> groupStrings(vector<string>& strings) {
//        vector<vector<string>> result;
//        unordered_map<string, vector<string>> hash;
//        string key;
//        sort(strings.begin(), strings.end());
//        for (string &s : strings) {
//            key = getKey(s);
//            hash[key].push_back(s);
//        }
//        for (auto it : hash) {
//            result.push_back(it.second);
//        }
//
//        return result;
//    }
//    string getKey(string s) {
//        string key = "";
//        for (unsigned i = 1; i < s.length(); i++) {
//            if (key.size() > 0) {
//                key += " ";
//            }
//            key += to_string(s[i]-s[i-1]<0?26+s[i]-s[i-1]:s[i]-s[i-1]);
//        }
//        return key;
//    }
//};

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> hash;
        string key;
        
        for (string &s : strings) {
            key = "";
            for (unsigned i = 1; i < s.length(); i++) {
                key += to_string(s[i]-s[i-1]<0?26+s[i]-s[i-1]:s[i]-s[i-1]);
                key += ",";
            }
            hash[key].push_back(s);
        }
        for (auto it : hash) {
            sort(it.second.begin(), it.second.end());
            result.push_back(it.second);
        }
        return result;
    }
};
