//
//  344.cpp
//  LeetCode
//
//  Created by roneil on 9/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string reverseString(string s) {
        string res;
        for (int i = s.length() - 1; i > -1; i--) {
            res.push_back(s[i]);
        }
        return res;
    }
};
//class Solution {
//public:
//    string reverseString(string s) {
//        int i = 0, j = s.size() - 1;
//        while(i < j){
//            swap(s[i++], s[j--]);
//        }
//        return s;
//    }
//};

//use swap function();