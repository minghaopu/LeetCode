//
//  246_247_248.cpp
//  LeetCode
//
//  Created by roneil on 12/7/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int n1 = (int) low.length(), n2 = (int) high.length();
        long long l1 = stoll(low), l2 = stoll(high);
        if (stol(low) > stol(high)) return 0;
        int l = 0, h = 0, count = 0;
        vector<string> ls = helper(n1, n1);
        vector<string> hs = helper(n2, n2);
        
        for (string s : ls) {
            
            long long n = stoll(s);
            if (n < l1) l++;
        }
        for (string s : hs) {
            long long n = stoll(s);
            if (n > l2) h++;
        }
        vector<int> dp(n2 + 1, 0);
        for (int i = 0; i <= n2; i++) {
            if (i == 0) dp[i] = 0;
            else if (i == 1) dp[i] = 3;
            else if (i == 2) dp[i] = 4;
            else if (i == 3) dp[i] = 12;
            else dp[i] = dp[i-2] * 5;
        }
        for (int i = n1; i <= n2; i++) count += dp[i];
        return count - l - h;
    }
    vector<string> findStrobogrammatic(int n) {
        return helper(n, n);
    }
    vector<string> helper(int n, int m) {
        if (n == 1) return {"0", "1", "8"};
        if (n == 0) return {""};
        vector<string> mid = helper(n-2, m);
        vector<string> res;
        for (string w : mid) {
            if (n != m) res.push_back("0" + w + "0"); // 00 is not valid
            res.push_back("1" + w + "1");
            res.push_back("8" + w + "8");
            res.push_back("6" + w + "9");
            res.push_back("9" + w + "6");
        }
        return res;
    }
    bool isStrobogrammatic(string num) {
        for (int i = 0, j = (int) num.length() - 1; i <= j; i++, j--) {
            char a = num[i], b = num[j];
            if (i == j) {
                if (a == '1' || a == '0' || a == '8') return true;
                else return false;
            } else {
                if (a == b && (a == '1' || a == '0' || a == '8')) continue;
                else if (a != b && ((a == '6' && b == '9') || (a == '9' && b == '6'))) continue;
                else return false;
            }
        }
        return true;
    }
};
