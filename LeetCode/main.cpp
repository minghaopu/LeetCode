//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//
#include "Header.h"
//#include "79.cpp"
//#include "Medium.cpp"
//#include "312. Burst Balloons.cpp"
//#include "Hard.cpp"
//#include "421. Maximum XOR of Two Numbers in an Array.cpp"
int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    int res = 0, height, width;
    stack<int> S;
    for (int i = 0; i < heights.size(); i++) {
        if (S.empty() || heights[S.top()] < heights[i]) S.push(i);
        else {
            while (!S.empty() && heights[S.top()] >= heights[i]) {
                height = heights[S.top()];
                S.pop();
                width = S.empty() ? i : i - (S.top() + 1);
                res = max(res, height * width);
            }
            S.push(i);
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> v {2,1,5,6,2,3};
    cout<<largestRectangleArea(v)<<endl;
    return 0;
}
