//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//


//#include "Medium.cpp"
#include "355. Design Twitter.cpp"


int main(int argc, const char * argv[]) {

    Twitter t(0);
    t.postTweet(1,5);
    vector<int> a = t.getNewsFeed(1);
    return 0;
}
