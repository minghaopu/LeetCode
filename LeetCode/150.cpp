//
//  150.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                
                if (token == "+") op1 += op2;
                else if (token == "-") op1 -= op2;
                else if (token == "*") op1 *= op2;
                else op1 /= op2;
                st.push(op1);
            } else st.push(stoi(token));
        }
        return st.top();
    }
};
