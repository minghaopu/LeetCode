//
//  460.cpp
//  LeetCode
//
//  Created by neal on 4/22/17.
//  Copyright © 2017 Minghao Pu. All rights reserved.
//

#include "Header.h"
class LFUCache {
private:
    int _cap;
    int _size;
    int minFreq;
    unordered_map<int, pair<int, int>> mapKtoVF; // key, value, frequency;
    unordered_map<int, list<int>::iterator> mapKtoIt; // key, iterator;
    unordered_map<int, list<int>> mapFtoK; // frequency, keys [];
    void move(int key) {
        pair<int, int> p = mapKtoVF[key];
        int frequency = p.second;
        mapFtoK[frequency].erase(mapKtoIt[key]);
        frequency++;
        mapKtoVF[key].second++;
        mapFtoK[frequency].push_back(key);
        mapKtoIt[key] = --mapFtoK[frequency].end();
        if (mapFtoK[minFreq].empty()) minFreq++;
    }
public:
    LFUCache(int capacity) {
        _cap = capacity;
        _size = 0;
        minFreq = 0;
    }
    
    int get(int key) {
        if (mapKtoVF.count(key) == 0) return -1;
        move(key);
        return mapKtoVF[key].first;
    }
    
    void put(int key, int value) {
        if (_cap <= 0) return;
        if (mapKtoVF.count(key) == 0) {
            pair<int, int> p = {value, 1};
            
            if (_cap == _size) {
                int oldKey = mapFtoK[minFreq].front();
                mapFtoK[minFreq].pop_front();
                mapKtoIt.erase(oldKey);
                mapKtoVF.erase(oldKey);
                _size--;
            }
            
            mapKtoVF[key] = p;
            mapFtoK[1].push_back(key);
            mapKtoIt[key] = --mapFtoK[1].end();
            _size++;
            minFreq = 1;
        } else {
            move(key);
            mapKtoVF[key].first = value;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
