//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//


#include "266_Palindrome_Permutation.cpp"



int main(int argc, const char * argv[]) {

    std::unordered_map<char, int> letter_counts;
    Solution so;
    string s = "aaa";
    so.canPermutePalindrome(s);
    
    return 0;
}
