//
//  255.cpp
//  LeetCode
//
//  Created by roneil on 12/8/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;
        int low = INT_MIN;
        for (int node : preorder) {
            if (node < low) return false;
            while (!s.empty() && node > s.top()) {
                low = s.top();
                s.pop();
            }
            s.push(node);
        }
        return true;
    }
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> s;
        int high = INT_MAX;
        for (int i = 0; i < postorder.size(); i++) {
            if (postorder[i] > high) return false;
            while (!s.empty() && postorder[i] < s.top()) {
                high = s.top();
                s.pop();
            }
            s.push(postorder[i]);
        }
        return true;
    }
    bool verifyInorder(vector<int>& inorder) {
        for (int i = 0; i < inorder.size() - 1; i++) {
            if (inorder[i] >= inorder[i+1]) return false;
        }
        return true;
    }
};
