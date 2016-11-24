//
//  Hard.cpp
//  LeetCode
//
//  Created by roneil on 11/22/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:
    /*
     *
     *      4. Median of Two Sorted Arrays
     *
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = int(nums1.size());
        int n = int(nums2.size());
        
        if (n == 0) return (double(nums1[(m-1)/2]) + double(nums1[m/2]))/2;
        
        int low = 0, high = 2 * n;
        while (low <= high) {
            int mid2 = (low + high) / 2;
            int mid1 = m + n - mid2;
            
            double l1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];
            double l2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
            double r1 = (mid1 == 2 * m) ? INT_MAX : nums1[mid1/2];
            double r2 = (mid2 == 2 * n) ? INT_MAX : nums2[mid2/2];
            
            if (l1 > r2) low = mid2 + 1;
            else if (l2 > r1) high = mid2 - 1;
            else return (max(l1, l2) + min(r1, r2))/2;
        }
        return -1;
    }
    /*
     *
     *      42. Trapping Rain Water
     *
     */
    int trap_TLE(vector<int>& height) {
        int total = 0;
        height.push_back(0);
        int left = 0;
        int n = int(height.size()) - 1;
        for (int i = 0; i < n; i++) {
            if (height[i] == left) continue;
            if (height[i] > left) left = height[i];
            int j = i + 1;
            while (j < n) {
                if (left > height[j]) {
                    int right = 0;
                    for (int k = j + 1; k < n; k++) {
                        if (height[k] > height[j]) {
                            right = max(height[k], right);
                        }
                    }
                    if (right != 0) {
                        total += min(left,right) - height[j];
                        height[j] = min(left,right);
                    }
                }
                j++;
            }
        }
        return total;
    }
    int trap(vector<int>& A) { //O(n)
        int left = 0, right = int(A.size()) - 1;
        int maxLeft = 0, maxRight = 0, total;
        while (left <= right) {
            if (A[left] <= A[right]) {
                if (A[left] > maxLeft) maxLeft = A[left];
                else total += maxLeft - A[left];
                left++;
            } else {
                if (A[right] > maxRight) maxRight = A[right];
                else total += maxRight - A[right];
                right--;
            }
        }
        return total;
    }
    /*
     *
     *      149. Max Points on a Line
     *
     */
    int maxPoints(vector<Point>& points) {
        int res = 0;
        int sz = int(points.size());
        if(sz<2) return sz;
        for (int i = 0; i < sz; i++) {
            map<pair<int,int>, int> lines;
            int overlap = 1, vertical = 0, horizontal = 0, localmax = 0;
            for (int j = i + 1; j < sz; j++) {
                Point A = points[i];
                Point B = points[j];
                if (A.x == B.x && A.y == B.y) {
                    overlap++;
                } else if (A.x == B.x) {
                    vertical++;
                } else if (A.y == B.y) {
                    horizontal++;
                } else {
                    int dx = A.x - B.x;
                    int dy = A.y - B.y;
                    int d = gcd(dx,dy);
                    dx = dx/d;
                    dy = dy/d;
                    lines[make_pair(dx, dy)]++;
                    localmax = max(localmax, lines[make_pair(dx, dy)]);
                }
            }
            res = max(res, overlap + max(vertical, max(horizontal, localmax)));
        }
        return res;
    }
    int gcd(int a, int b) {
        if (b == 0) return a;
        else return gcd(b, a%b);
    }
    /*
     *
     *      138. Copy List with Random Pointer
     *
     */
    RandomListNode *copyRandomList(RandomListNode *head) {// O(n), O(n);
        if (!head) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> cache;
        RandomListNode* pre = new RandomListNode(0);
        RandomListNode* newHead = pre;
        RandomListNode *p = head;
        while (p) {
            pre->next = new RandomListNode(p->label);
            cache[p] = pre->next;
            pre = pre->next;
            p = p->next;
        }
        pre = newHead;
        while (head) {
            pre->next->random = cache[head->random];
            pre = pre->next;
            head = head->next;
        }
        return newHead->next;
    }
    RandomListNode *copyRandomList_O_n_Space(RandomListNode *head) {
        RandomListNode* pre = new RandomListNode(0);
        RandomListNode* newHead = pre;
        RandomListNode *p = head;
        while (p) {
            RandomListNode* copy = new RandomListNode(p->label);
            copy->next = p->next;
            p->next = copy;
            p = copy->next;
        }
        p = head;
        while (p) {
            if (p->random) {
                p->next->random = p->random->next; // p->random->next points to the copy; p->random points to the original;
            }
            p = p->next->next;
        }
        p = head;
        while (p) {
            pre->next = p->next;
            p->next = p->next->next;
            p = p->next;
            pre = pre->next;
        }
        return newHead->next;
    }
    /*
     *
     *      138. Copy List with Random Pointer
     *
     */
    bool isSelfCrossing(vector<int>& x) {
        int len = int(x.size());
        for (int i = 3; i < len; i++) {
            if (x[i] >= x[i-2] && x[i-1] <= x[i-3]) return true;
            if (i > 3 && x[i] + x[i-4] >= x[i-2] && x[i-1] == x[i-3]) return true;
            if (i > 4 && x[i-2] >= x[i-4] && x[i] + x[i-4] >= x[i-2] && x[i-1] <= x[i-3] && x[i-1] + x[i-5] >= x[i-3]) return true;
        }
        return false;
    }
    /*
     *
     *      10. Regular Expression Matching
     *
     */
    bool isMatch(string s, string p) {
        int m = int(s.length()), n = int(p.length());
        
        vector<vector<int>> dp(m, vector<int> (n, 0));
        //int dp[m+1][n+1]{{0}};
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                }else {
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        return dp[m][n];
    }
    /*
     *
     *      233. Number of Digit One
     *
     */
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        if (n <= 9) return 1;
        int len = to_string(n).length();// 2234, lenthg is 4;
        int num = pow(10, len - 1); // num = 10^(4-1) = 1000;
        if (n >= 2 * num) return num + countDigitOne(n % num) + (n/num) * countDigitOne(num - 1);
        // 1000 + count(234) + 2 * count(999);
        else return n%num + 1 + countDigitOne(n % num) + countDigitOne(num - 1);
        //if 1234; then 1000~1234->234+1, + count(234) + count(999);
    }
    /*
     *
     *      23. Merge k Sorted Lists
     *
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](const int a, const int b) {return a < b;};
        map<int, ListNode*, decltype(comp)> cache(comp);
        for (int i = 0; i < lists.size(); i++) {
            ListNode* p = lists[i];
            ListNode* next;
            while (p) {
                next = p->next;
                p->next = NULL;
                if (cache.find(p->val) == cache.end()) {
                    cache[p->val] = new ListNode(0);
                    cache[p->val]->next = p;
                } else {
                    ListNode* k = cache[p->val];
                    while (k->next) k = k->next;
                    k->next = p;
                }
                p = next;
            }
        }
        ListNode* newHead = new ListNode(0);
        ListNode* p = newHead;
        for (auto it = cache.begin(); it != cache.end(); it++) {
            p->next = it->second->next;
            while (p->next) p = p->next;
        }
        return newHead->next;
    }
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        auto comp = [](const ListNode* a, const ListNode* b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> heap(comp);
        ListNode* newHead = new ListNode(0);
        ListNode* cur = newHead;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) heap.push(lists[i]);
        }
        while (!heap.empty()) {
            cur->next = heap.top();
            heap.pop();
            cur = cur->next;
            if (cur->next) heap.push(cur->next);
        }
        return newHead->next;
    }
    /*
     *
     *      287. Find the Duplicate Number
     *
     */
    // similar to Linked List Cycle II
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int slow = nums[0], fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
    /*
     *
     *      287. Find the Duplicate Number
     *
     */
    int minDistance(string word1, string word2) {
        int m = int(word1.length()), n = int(word2.length());
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
//        int dp[m+1][n+1]{{0}};
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int i = 0; i <= n; i++) dp[0][i] = i;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
        return dp[m][n];
    }
    /*
     *
     *      84. Largest Rectangle in Histogram
     *
     */
    int largestRectangleArea(vector<int>& A) {
        int res = 0;
        A.push_back(0);
        stack<int> S; // Store index position
        for (int i = 0; i < A.size(); i++) {
            while (S.size() > 0 && A[S.top()] >= A[i]) {
                int h = A[S.top()];
                S.pop();
                int leftIndex = S.empty() ? -1 : S.top();
                if (h * (i - leftIndex - 1) > res) res = h * (i - leftIndex - 1);
            }
            S.push(i);
        }
        return res;
    }
    /*
     *
     *      56. Merge Intervals
     *
     */
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() < 2) return intervals;
        auto comp = [](const Interval a, const Interval b){return a.start < b.start || (a.start == b.start && a.end < b.end);};
        sort(intervals.begin(), intervals.end(), comp);
        int start = intervals[0].start, end = intervals[0].end;
        vector<Interval> res;
        for (int i = 1; i < intervals.size(); i++) {
            auto it = intervals[i];
            if (it.start > end) {
                res.push_back(Interval (start, end));
                start = it.start;
                end = it.end;
            }else if (it.end > end) end = it.end;
        }
        res.push_back(Interval (start, end));
        return res;
    }
    /*
     *
     *      164. Maximum Gap
     *
     */
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int l = int(nums.size());
        int minN = INT_MAX, maxN = INT_MIN;
        for (int n : nums) {
            if (minN > n) minN = n;
            if (maxN < n) maxN = n;
        }
        int bucketLength = (maxN - minN) / l + 1;
        int bucketNum = (maxN - minN) / bucketLength + 1;
        vector<vector<int>> buckets(bucketNum, vector<int> {INT_MAX, INT_MIN});
        for (int n : nums) {
            int pos = (n - minN) / bucketLength;
            if (n < buckets[pos][0]) buckets[pos][0] = n;
            if (n > buckets[pos][1]) buckets[pos][1] = n;
        }
        int gap = 0;
        int pre = 0;
        for (int i = 1; i < bucketNum; i++) {
            if (buckets[i][0] == INT_MAX) continue;
            gap = max(gap, buckets[i][0] - buckets[pre][1]);
            pre = i;
        }
        return gap;
    }
    /*
     *
     *      128. Longest Consecutive Sequence
     *
     */
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 1;
        unordered_map<int, int> cache;
        for (int i = 0; i < nums.size(); i++) cache[nums[i]] = 0;
        int length = 0;
        for (int n : nums) {
            if (cache[n]) continue;
            int right = n;
            int left = n;
            while (cache.find(right) != cache.end()) cache[right++] = 1;
            while (cache.find(left) != cache.end()) cache[left--] = 1;
            length = max(right - left - 1, length);
        }
        return length;
    }
    /*
     *
     *      128. Longest Consecutive Sequence
     *
     */
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> res;
        int cur = 0, curX, curH, len = int(buildings.size());
        priority_queue<pair<int,int>> Q;
        while (cur < len || !Q.empty()) {
            if (Q.empty() || (cur < len && buildings[cur][0] <= Q.top().second)) {
                curX = buildings[cur][0];
                while (cur < len && buildings[cur][0] == curX) {
                    Q.push({buildings[cur][2], buildings[cur][1]});
                    cur++;
                }
            } else {
                curX = Q.top().second;
                while (!Q.empty() && Q.top().second <= curX) Q.pop();
            }
            curH = Q.empty()? 0 : Q.top().first;
            if (res.empty() || curH != res.back().second) {
                res.push_back({curX, curH});
            }
        }
        return res;
    }
    /*
     *
     *      316. Remove Duplicate Letters
     *
     */
    string removeDuplicateLetters(string s) {
        int cache[26];
        int visited[26];
        int count = 26;
        memset(cache, 0, sizeof(cache));
        memset(visited, 0, sizeof(visited));
        for (char c : s) cache[c-'a']++;
        stack<int> S;
        string res;
        for (char c : s) {
            int i = c - 'a';
            cache[i]--;
            if (visited[i]) continue;
            while (!res.empty() && res.back() > c && cache[res.back() - 'a'] > 0) {
                visited[res.back() - 'a'] = 0;
                res.pop_back();
                count++;
            }
            res.push_back(c);
            if (count-- == 0) return res;
            visited[i] = 1;
        }
        return res;
    }
};
