//
//  68.cpp
//  LeetCode
//
//  Created by roneil on 12/1/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int start = 0, end = 1, n = words.size();
        while (start < n) {
            int space = 1;
            int wordLength = (int)words[start].length();
            while (end < n && wordLength + space + words[end].length() <= maxWidth) {
                wordLength += words[end++].length();
                space++;
            }
            string line = words[start];
            if (end == n) {
                for (int i = start + 1; i < end; i++) line += " " + words[i];
                line.append(maxWidth - (int)line.length(), ' ');
            } else if (end - start == 1) {
                line.append(maxWidth - (int)line.length(), ' ');
            } else {
                int average = (maxWidth - wordLength) / (end - start - 1);
                int remain = (maxWidth - wordLength) % (end - start - 1);
                for (int i = start + 1; i < end; i++) {
                    line.append(average, ' ');
                    if (remain-- > 0) line += ' ';
                    line += words[i];
                }
            }
            start = end;
            end++;
            res.push_back(line);
        }
        return res;
    }
};
