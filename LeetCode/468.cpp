//
//  468.cpp
//  LeetCode
//
//  Created by neal on 12/18/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    string validIPAddress(string IP) {
        if (isValidIP4(IP)) return "IPv4";
        else if (isValidIP6(IP)) return "IPv6";
        return "Neither";
    }
    bool isValidIP4(string ip) {
        if (ip.length() < 7) return false;
        if (ip.find_last_of('.') == ip.length() - 1) return false;
        stringstream ss(ip);
        string token;
        int count = 0;
        while (getline(ss, token, '.')) {
            count++;
            if (token.empty()) return false;
            if (token[0] == '0' && token.length() > 1) return false;
            int num = 0;
            for (char c : token) {
                if (c > '9' || c < '0') return false;
                num = num * 10 + c - '0';
                if (num > 255 || num < 0) return false;
            }
        }
        return count == 4;
    }
    bool isValidIP6(string ip) {
        if (ip.length() < 15) return false;
        if (ip.find_last_of(':') == ip.length() - 1) return false;
        stringstream ss(ip);
        string token;
        int count = 0;
        while (getline(ss, token, ':')) {
            count++;
            if (token.empty() || token.length() > 4) return false;
            int num = 0;
            for (char c : token) {
                if (c <= '9' && c >= '0') num = num * 16 + c - '0';
                else if (c <= 'f' && c >= 'a') num = num * 16 + c - 'a';
                else if (c <= 'F' && c >= 'A') num = num * 16 + c - 'A';
                else return false;
                if (num > 65535 || num < 0) return false;
            }
        }
        return count == 8;
    }
};
