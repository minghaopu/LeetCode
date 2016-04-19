//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include <iostream>
#include "290_Word_Pattern.cpp"



int main(int argc, const char * argv[]) {
    string pattern = "abba";
    string str = "dog dog dog dog";
    Solution so(pattern,str);
    cout<<so.wordPattern()<<endl;

    
    return 0;
}
