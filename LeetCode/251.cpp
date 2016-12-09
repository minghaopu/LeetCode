//
//  251.cpp
//  LeetCode
//
//  Created by roneil on 12/7/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Vector2D {
private:
    vector<vector<int>>::iterator it, end;
    int shift;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        it = vec2d.begin();
        end = vec2d.end();
        shift = 0;
    }
    
    int next() {
        if (it != end && shift == (*it).size()) {
            it++;
            shift = 0;
            
        }
        return (*it)[shift++];
    }
    
    bool hasNext() {
        while (it != end && shift == (*it).size()) {
            it++;
            shift = 0;
        }
        return it != end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
