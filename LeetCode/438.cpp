//
//  438.cpp
//  LeetCode
//
//  Created by neal on 12/14/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pmap(26, 0), smap(26, 0), res;
        if (s.size() < p.size()) return {};
        int plength = (int) p.size();
        for (int i = 0; i < plength; i++) {
            smap[s[i]-'a']++;
            pmap[p[i]-'a']++;
        }
        if (smap == pmap) res.push_back(0);
        for (int i = plength; i < s.length(); i++) {//slide window;
            smap[s[i] - 'a']++;//right
            smap[s[i-plength] - 'a']--;//left;
            if (smap == pmap) res.push_back(i - plength + 1);
        }
        return res;
    }
};
