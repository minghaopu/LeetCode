//
//  271.cpp
//  LeetCode
//
//  Created by roneil on 11/16/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Codec {
public:
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res ="";
        for (int i = 0; i < strs.size(); i++) {
            res += to_string(strs[i].length()) +'@' + strs[i];
        }
        return res;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int head = 0;
        while (head < s.size()) {
            int po = s.find_first_of('@', head);
            int len = stoi(s.substr(head, po - head));
            head = po + 1;
            res.push_back(s.substr(head, len));
            head += len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
