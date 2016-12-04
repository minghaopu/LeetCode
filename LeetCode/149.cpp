//
//  149.cpp
//  LeetCode
//
//  Created by roneil on 12/3/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int size = (int)points.size();
        if (size < 2) return size;
        int res = 0;
        for (int i = 0; i < size; i++) {
            map<pair<int, int>, int> lines;
            int overlap = 1, vertical = 0, horizontal = 0, localMax = 0;
            for (int j = i+1; j < size; j++) {
                Point a = points[i];
                Point b = points[j];
                if (a.x == b.x && a.y == b.y) overlap++;
                else if (a.x == b.x) vertical++;
                else if (a.y == b.y) horizontal++;
                else {
                    int dx = a.x - b.x;
                    int dy = a.y - b.y;
                    int d = gcd(dx, dy);
                    dx /= d;
                    dy /= d;
                    pair<int, int> p = {dx, dy};
                    lines[p]++;
                    localMax = max(localMax, lines[p]);
                }
            }
            res = max(res, overlap + max(max(horizontal, vertical), localMax));
        }
        return res;
    }
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
};
