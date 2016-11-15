//
//  251.cpp
//  LeetCode
//
//  Created by roneil on 11/14/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Vector2D {
private:
    int index;
    vector<int> flat;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        index = 0;
        for (int i = 0; i < vec2d.size(); i++) {
            for (int j = 0; j < vec2d[i].size(); j++) {
                flat.push_back(vec2d[i][j]);
            }
        }
    }
    
    int next() {
        return flat[index++];
    }
    
    bool hasNext() {
        return index < flat.size();
    }
};
class Vector2D_iterator {
private:
    vector<vector<int>>::iterator it, itEnd;
    int shift;
public:
    Vector2D_iterator(vector<vector<int>>& vec2d) {
        shift = 0;
        itEnd = vec2d.end();
        it = vec2d.begin();
    }
    
    int next() {
        hasNext();
        return (*it)[shift++];
    }
    
    bool hasNext() {
        while (it != itEnd && shift == (*it).size()) {
            it++;
            shift = 0;
        }
        return it != itEnd;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */