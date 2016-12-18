//
//  379.cpp
//  LeetCode
//
//  Created by neal on 12/12/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class PhoneDirectory {
private:
    vector<bool> used;
    vector<int> dictionary;
    int maxN;
    int index;
public:
    /** Initialize your data structure here
     @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        maxN = maxNumbers;
        used.assign(maxN, true);
        dictionary.resize(maxN);
        for (int i = 0; i < maxN; i++) dictionary[i] = i;
        index = 0;
    }
    
    /** Provide a number which is not assigned to anyone.
     @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (index == maxN) return -1;
        int res = dictionary[index++];
        used[res] = false;
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return used[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (used[number] == false) {
            used[number] = true;
            dictionary[--index] = number;
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
