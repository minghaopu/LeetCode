//
//  159_340_395.cpp
//  LeetCode
//
//  Created by roneil on 12/4/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int map[128] = {0};
        int start = 0, i, count = 0, maxLength = 0;
        for (i = 0; i < s.length(); i++) {
            if (map[s[i]]++ == 0) count++;
            maxLength = max(maxLength, i - start);
            while (start < i && count > 2) {
                map[s[start]]--;
                if (map[s[start]] == 0) count--;
                start++;
            }
        }
        if (i > start) maxLength = max(maxLength, i - start);
        return maxLength;
    }
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0 || s == "") return 0;
        int map[128] = {0};
        int start = 0, i, count = 0, maxLength = 0;
        for (i = 0; i < s.length(); i++) {
            if (map[s[i]]++ == 0) count++;
            maxLength = max(maxLength, i - start);
            while (start < i && count > k) {
                map[s[start]]--;
                if (map[s[start]] == 0) count--;
                start++;
            }
        }
        if (i > start) maxLength = max(maxLength, i - start);
        return maxLength;
    }
    int longestSubstring(string s, int k) {
        if (s == "" || k > s.length()) return 0;
        if (k == 0) return (int) s.length();
        int map[26] = {0};
        for (char c : s) map[c-'a']++;
        int i = 0, l = (int) s.length();
        while (i < l && map[s[i]-'a'] >= k) i++;
        if (i == l) return l;
        
        int left = longestSubstring(s.substr(0, i), k);
        int right = longestSubstring(s.substr(i+1), k);
        return max(left, right);
    }
};
