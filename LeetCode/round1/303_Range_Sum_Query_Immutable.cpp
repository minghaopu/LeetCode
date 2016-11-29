//
//  303_Range_Sum_Query_Immutable.cpp
//  LeetCode
//
//  Created by roneil on 16/4/17.
//  Copyright © 2016年 Minghao Pu. All rights reserved.
//

#include <map>
#include <utility>
#include <vector>

using namespace std;
/*
 * Use Map
 */

//class NumArray {
//private:
//    vector<int> data;
//    map<pair<int, int>,int> sums;
//public:
//    NumArray(vector<int> &nums) {
//        data = nums;
//        for (int i = 0; i < data.size(); i++) {
//            int sum = 0;
//            for (int j = 0; i+j < data.size(); j++) {
//                sum += data[j];
//                sums[make_pair(i,i+j)] =  sum;
//            }
//        }
//    }
//    
//    int sumRange(int i, int j) {
//        if (i<0 || j > data.size()) return 0;
//        map<pair<int, int>,int>::iterator it;
//        it = sums.find(make_pair(i,j));
//        if (it != sums.end()) {
//            return sums[make_pair(i,j)];
//        }else {
//            return 0;
//        }
//        
//    }
//};

/*
 * Use Vector
 */
//class NumArray {
//private:
//    vector<int> data;
//    vector<int> sums {0};
//public:
//    NumArray(vector<int> &nums) {
//        data = nums;
//        int sum = 0;
//        for (int i = 0; i < data.size(); i++) {
//            sum += data[i];
//            sums.push_back(sum);
//        }
//    }
//    
//    int sumRange(int i, int j) {
//        if (i<0 || j > data.size()) return 0;
//        return sums[j+1]-sums[i];
//    }
//};

/*
 * Use Array
 */

//class NumArray {
//private:
//    int *sums;
//public:
//    NumArray(vector<int> &nums) {
//        int length = nums.size();
//        sums = new int [length+1];
//        sums[0] = 0;
//        int sum = 0;
//        for (int i = 1; i <= length; i++) {
//            sum += nums[i-1];
//            sums[i] = sum;
//        }
//    }
//    
//    int sumRange(int i, int j) {
//        return sums[j+1]-sums[i];
//    }
//    ~NumArray () {
//        delete [] sums;
//    }
//};

/*
 * Use Array in compression. runtime >98% submission
 */

class NumArray {
private:
    int *ss;
public:
    NumArray(vector<int> &nums) {
        int l = int(nums.size());
        ss = new int [l+1];
        ss[0] = 0;
        int k = 0;
        for (int i = 1; i <= l; i++) {
            k += nums[i-1];
            ss[i] = k;
        }
    }
    
    int sumRange(int i, int j) {
        return ss[j+1]-ss[i];
    }
};
