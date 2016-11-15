//
//  288_Unique_Word_Abbreviation.cpp
//  LeetCode
//
//  Created by roneil on 16/4/19.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class ValidWordAbbr {
    unordered_map<string, unordered_set<string> > abd;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        
        for (int i = 0; i < dictionary.size(); i++) {
            string s = dictionary[i];
            int l = (int)s.length();
            if (s == "") {
                continue;
            }
            string t = s;
            abd[t.replace(1, l-2, to_string(l))].insert(s);
        }
    }
    
    bool isUnique(string word) {
        int l = (int)word.length();
        if (abd.size()==0 || l == 0) return true;
        
        string t = word;
        if (abd[t.replace(1, l-2, to_string(l))].count(word)==abd[t].size()) {
            return true;
        }
        return false;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
