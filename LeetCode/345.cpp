//
//  345.cpp
//  LeetCode
//
//  Created by roneil on 9/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    void swap(string &s, int ind1, int ind2){
        int temp = s[ind2];
        s[ind2] = s[ind1];
        s[ind1] = temp;
    }
    
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    
    string reverseVowels(string s) {
        int start = 0, end = s.length() - 1;
        while (start < end){
            while (start < end && !isVowel(s[start])) start++;
            while (start < end && !isVowel(s[end])) end--;
            swap(s, start, end);
            start++;
            end--;
        }
        return s;
    }
};