//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include "Header.h"
//#include "Medium.cpp"
//#include "312. Burst Balloons.cpp"
//#include "Hard.cpp"
//#include "421. Maximum XOR of Two Numbers in an Array.cpp"
int strStr(string haystack, string needle) {
    if (needle == "") return 0;
    if (haystack == "") return -1;
    
    int m = (int)haystack.length(), n = (int)needle.length();
    //        vector<int> next(n, 0);
    int next[n];
    memset(next, 0, sizeof(next));
    for (int i = 0; i < n; i++) cout<<next[i]<<endl;
    //        int j = -1;
    // for (int i = 1; i <)
    return 0;
}
int main(int argc, const char * argv[]) {
    string word = "ZZZfdsafdsfdsafdsafdsaaZ";
    strStr("fdsafdsa", word);
    return 0;
}
