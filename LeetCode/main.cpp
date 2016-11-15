//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//


#include "Medium.cpp"
//#include "281.cpp"


int main(int argc, const char * argv[]) {
    vector<pair<int, int>> pre = {{0,1},{0,2},{1,2}};
    vector<int> v2 = {7,8,9,10};
    Solution so;
    so.canFinish(3, pre);
    return 0;
}
