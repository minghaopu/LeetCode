//
//  main.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include <iostream>
#include "293_File_Game.cpp"



int main(int argc, const char * argv[]) {
    string ss = "--";
    string ss1 = ss;
    ss1[0] = '-';
    ss1[1] = '-';

    Solution s(ss);
    vector<string> result = s.generatePossibleNextMoves();
    for (int i = 0; i < result.size(); i++) {
        cout<<result[i]<<endl;
    }
    return 0;
}
