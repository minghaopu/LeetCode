//
//  379. Design Phone Directory.cpp
//  LeetCode
//
//  Created by roneil on 11/20/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class PhoneDirectory {
    vector<int> dic;
    vector<int> used;
    int upper;
    int front;
    int rear;
public:
    /** Initialize your data structure here
     @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        dic.resize(maxNumbers + 1, 0);
        used.resize(maxNumbers + 1);
        front = rear = 0;
        upper = maxNumbers - 1;
        for (int i = 0; i < maxNumbers; i++) {
            dic[rear++] = i;
        }
    }
    
    /** Provide a number which is not assigned to anyone.
     @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (front >= rear) return - 1;
        int res = dic[front++];
        used[res] = 1;
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (number < 0 || number > upper) return false;
        return used[number] == 0;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number >= 0 && number <= upper && used[number] == 1) {
            used[number] = 0;
            front--;
            dic[front] = number;
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
