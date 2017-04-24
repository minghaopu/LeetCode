//
//  yelpOA.cpp
//  LeetCode
//
//  Created by neal on 4/12/17.
//  Copyright © 2017 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string stringCompression(string s) {
        if (s.length() < 2) return s;
        string res = "";
        int count = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                count++;
                if (i == s.length() - 1) {
                    if (count > 1) res += to_string(count);
                    res += s[i];
                }
            } else {
                if (count > 1) res += to_string(count);
                res += s[i-1];
                count = 1;
            }
        }
        return res;
    }
    string reverseSentence(string s) {
        if (s.length() < 2) return s;
        stringstream ss(s);
        string token;
        s = "";
        while (getline(ss, token, ' ')) {
            if (token != "") s = token + ' ' + s;
        }
        if (s != "") s.pop_back();
        return s;
    }
    
    bool isAnagram(string s1, string s2) {
        int map[128] = {0};
        for (int i = 0; i < s1.length(); i++) {
            map[s1[i]]++;
            map[s2[i]]--;
        }
        for (int i = 0; i < 128; i++) {
            if (map[i] != 0) {
                cout<<"Not Anagram"<<endl;
                return false;
            }
        }
        cout<<"Anagram"<<endl;
        return true;
    }
    vector<string> topColor(vector<vector<string>>& matrix) {
        vector<string> res;
        map<string, int> cache;
        int maxCount = 0;
        for (auto row : matrix) {
            for (string color : row) {
                cache[color]++;
                if (cache[color] > maxCount) maxCount = cache[color];
            }
        }
        for (auto it = cache.begin(); it != cache.end(); it++) {
            if (it->second == maxCount) res.push_back(it->first);
        }
    
        for (int i = 0; i < res.size(); i++) cout<<res[i]<<endl;
        return res;
    }
    string findRestaurant(vector<string>& r1, vector<string>& r2) {
        string res = "";
        map<string, int> cache;
        int rank = 0;
        int minRank = INT_MAX;
        for (int i = 0; i < r1.size(); i++) {
            cache[r1[i]] = i;
        }
        for (int i = 0; i < r2.size(); i++) {
            if (cache.find(r2[i]) != cache.end()) {
                cache[r2[i]] += i;
                rank = cache[r2[i]];
                if (rank < minRank) {
                    minRank = rank;
                    res = r2[i];
                }
            }
        }
        return res == "" ? "Yelpwich" : res;
    }
    bool checkPalindrome(string s) {
        int oddCount = 0;
        int map[128] = {0};
        for (char c : s) {
            map[c]++;
        }
        for (int i = 0; i < 128; i++) {
            if (map[i] & 1) {
                oddCount++;
                if (oddCount > 1) return false;
            }
        }
        return true;
    }
    int midInfo (vector<Info> ls) {
//        sort(nums.begin(), nums.end(), [](const int a, const int b) {
//            string sa = to_string(a), sb = to_string(b);
//            return sa + sb > sb + sa;
//        });
        sort(ls.begin(), ls.end(), [](const Info a, const Info b){
            return a.rating - b.rating;
        });
        int size = (int) ls.size();
        if (size & 1) {
            return ls[size / 2].rating;
        } else {
            return (ls[(size-1) / 2].rating + ls[size / 2].rating) / 2;
        }
    }
//    cin >> n;
//    vector<int> arr(n);
//    for(int arr_i = 0;arr_i < n;arr_i++){
//        cin >> arr[arr_i];
//    }
};
