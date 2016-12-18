//
//  418.cpp
//  LeetCode
//
//  Created by neal on 12/13/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s = "";
        for (string word : sentence) s += word + ' ';
        int start = 0;
        int l = (int)s.length();
        for (int i = 0; i < rows; i++) {
            start += cols;
            while (start > 0 && s[start % l] != ' ') start--;
            start++;
        }
        return start / l;
    }
};
