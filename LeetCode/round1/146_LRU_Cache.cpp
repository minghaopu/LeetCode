//
//  146_LRU_Cache.cpp
//  LeetCode
//
//  Created by roneil on 10/5/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class LRUCache{
private:
    list<pair<int, int>> cache;
    int _cap;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    void moveToFront(int key) {
        auto newEntry = *map[key];
        cache.erase(map[key]);
        cache.push_front(newEntry);
        map[key] = cache.begin();
    }
public:
    LRUCache(int capacity) {
        _cap = capacity;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        else {
            moveToFront(key);
            return cache.front().second;
        }
    }
    
    void set(int key, int value) {
        if (map.find(key) != map.end()) {
            moveToFront(key);
            map[key]->second = value;
        } else {
            pair<int, int> newItem = {key, value};
            if (map.size() >= _cap) {
                map.erase(cache.back().first);
                cache.pop_back();
            }
            cache.push_front(newItem);
            map[key] = cache.begin();
        }
    }
};
