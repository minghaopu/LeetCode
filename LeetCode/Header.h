//
//  Header.h
//  LeetCode
//
//  Created by roneil on 16/4/20.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <regex>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <sstream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL) {}
};
vector<string> split(string s, char seperator) {
    vector<string> elems;
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, seperator)) {
        elems.push_back(item);
    }
    return elems;
}
#endif /* Header_h */



