//
//  93.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string s1, s2, s3, s4;
        int first, second, third;
        int length = (int)s.length();
        if (length > 12 || length < 4) return {};
        for (first = 1; first < 4; first++) {
            s1 = s.substr(0, first);
            if ((s1[0] == '0' && s1.length() > 1) || stoi(s1) >= 256) break;
            
            for (second = first + 1; second < length && second < first + 4; second++) {
                s2 = s.substr(first, second - first);
                if ((s2[0] == '0' && s2.length() > 1) || stoi(s2) >= 256) break;
                
                for (third = second + 1; third < length && third < second + 4; third++) {
                    s3 = s.substr(second, third - second);
                    
                    if ((s3[0] == '0' && s3.length() > 1) || stoi(s3) >= 256) break;
                    
                    s4 = s.substr(third);
                    if ((s4[0] == '0' && s4.length() > 1) || stoi(s4) >= 256) continue;
                    res.push_back(s1 + '.' + s2 + '.' + s3 + '.' + s4);
                }
            }
        }
        return res;
    }
};
