//
//  Medium.cpp
//  LeetCode
//
//  Created by roneil on 9/20/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:

    /*
     *
     *      151  Reverse Words in a String
     *
     */
    void reverseWords(string &s) {
        vector<string> stack;
        string newS = "";
        int i, j;
        for (i = 0, j = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (i != j) {
                    stack.push_back(s.substr(j, i - j));
                    j = i + 1;
                }else {
                    j++;
                }
            }
        }
        if (i != j) stack.push_back(s.substr(j, i - j));
        for (i = stack.size() - 1; i > -1 ; i--) {
            newS += stack[i] + ' ';
        }
        s = newS.substr(0, newS.length() - 1);
    }
    /*
     *
     *      3  Longest Substring Without Repeating Characters
     *
     */
    int lengthOfLongestSubstring(string s) {
        int map[128];
        memset(map, -1, sizeof(map));
        int res = 0;
        int cur, last;
        for (cur = 0, last = -1; cur < s.length(); cur++) {
            if (map[s[cur]] > last) last = map[s[cur]];
            map[s[cur]] = cur;
            res = max(res, cur - last);
        }
        if (cur != last) res = max(res, last - cur);
        return res;
    }
    
    /*
     *
     *      5   Longest Palindromic Substring
     *
     */
    string longestPalindrome(string s) {
        int l = s.length();
        int longestBegin = 0;
        int max = 1;
        bool table[1000][1000] = {false};
        for (int i = 0; i < l; i++) {
            table[i][i] = true;
        }
        for (int i = 0; i < l; i++) {
            if (s[i] == s[i+1]) {
                table[i][i+1] = true;
                longestBegin = i;
                max = 2;
            }
        }
        for (int len = 3; len <= l; len++) {
            for (int i = 0; i < l - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && table[i+1][j-1]) {
                    table[i][j] = true;
                    longestBegin = i;
                    max = len;
                }
            }
        }
        return s.substr(longestBegin, max);
    }
    /*
     *
     *      15   3sum
     *
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        int a;
        int b;
        int c;
        int len = nums.size();
        
        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            a = nums[i];
            
            int l = i + 1;
            int r = len - 1;
            while (l < r) {
                b = nums[l];
                c = nums[r];
                if (a + b + c == 0) {
                    vector<int> temp = {a, b, c};
                    result.push_back(temp);
                    while (nums[l]==nums[l+1]) l++;
                    while (nums[r]==nums[r-1]) r--;
                    l++;
                    r--;
                } else if (a + b + c < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return result;
    }
};
