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
        int len = int(to_string(n).length());// 2234, lenthg is 4;
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
    /*
     *
     *      123. Best Time to Buy and Sell Stock III
     *
     */
    int maxProfit_III(vector<int>& prices) {
        int buy1 = INT_MIN, buy2 = INT_MIN;
        int sell1 = 0, sell2 = 0;
        for (int price : prices) {
            sell2 = max(sell2, buy2 + price);
            buy2 = max(buy2, sell1 - price);
            sell1 = max(sell1, buy1 + price);
            buy1 = max(buy1, -price);
        }
        return sell2;
    }
    /*
     *
     *      123. Best Time to Buy and Sell Stock IV
     *
     */
    int maxProfit_IV(int k, vector<int>& prices) {
        int n = int(prices.size());
        // if k >= n / 2 which means buy and sell no limitation
        if (k>=n/2) {
            int sum = 0;
            for(int i=1; i<n; i++){
                if(prices[i] > prices[i-1]){
                    sum += prices[i] - prices[i-1];
                }
            }
            return sum;
        }
        int buys[k+1];
        int sells[k+1];
        
        for (int i= 0; i<= k; i++) {
            buys[i] = INT_MIN;
            sells[i] = 0;
        }
        for (int price: prices) {
            for (int i = k; i > 0; i--) {
                sells[i] = max(sells[i], buys[i] + price);
                buys[i] = max(buys[i], sells[i-1] - price);
            }
        }
        return sells[k];
    }
    /*
     *
     *      41. First Missing Positive
     *
     */
    int firstMissingPositive(vector<int>& A) {
        int n = int(A.size());
        int i = 0;
        while (i < n) {
            if (A[i] == i+1 || A[i] <= 0 || A[i] > n || A[A[i]-1] == A[i]) i++;
            else swap(A[i], A[A[i]-1]);
        }
        for (int i = 0; i < n; i++) {
            if (A[i] != i+1) return i+1;
        }
        return n+1;
    }
    /*
     *
     *      41. First Missing Positive
     *
     */
    int numDistinct_TLE(string s, string t) {
        if (s.size() < t.size()) return 0;
        if (s == t) return 1;
        if (s[0] != t[0]) return numDistinct_TLE(s.substr(1), t);
        else return numDistinct_TLE(s.substr(1), t.substr(1)) + numDistinct_TLE(s.substr(1), t);
    }
    int numDistinct(string s, string t) { // 6ms O(mn) for space and time;
        int m = int(s.length()), n = int(t.length());
        int dp[m+1][n+1];
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
    int numDistinct3(string s, string t) { // 3ms O(n) space
        // the index of prefix indicate the index of t
        // prefix stores the numbers of t's prefixes occur when we iterate through s.
        // the dp equation is when we encounter a character which also occurs in t at position i, then prefixVec[i] += prefixVec[i-1] (i > 0), prefixVec[i]++ (i = 0).
        int n = int(t.length());
        int prefix[n+1];
        prefix[0] = 1; //sentinel
        for (char c : s) {
            for (int j = n; j > 0; j--) {
                if (c == t[j-1]) prefix[j] += prefix[j-1];
            }
        }
        return prefix[n];
    }
    /*
     *
     *      124. Binary Tree Maximum Path Sum
     *
     */
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int res = INT_MIN;
        helper_124(root, res);
        return res;
    }
    int helper_124(TreeNode* node, int &res) {
        if (node == NULL) return 0;
        int tmp = node->val;
        int left = helper_124(node->left, res), right = helper_124(node->right, res);
        // if node is in the path
        res = max(tmp + left + right, res);
        // node not in the path
        return max(0, max(left, right) + tmp);
    }
    /*
     *
     *      124. Binary Tree Maximum Path Sum
     *
     */
    int findMin(vector<int>& nums) {
        int start = 0, end = int(nums.size()) - 1;
        while (start < end) {
            while (start < end - 1 && nums[start] == nums[start+1]) start++;
            while (start < end - 1 && nums[end] == nums[end-1]) end--;
            int mid = (start + end) / 2;
            if (nums[mid] < nums[end]) end = mid;
            else start = mid + 1;
        }
        return nums[start];
    }
    /*
     *
     *      282. Expression Add Operators
     *
     */
    vector<string> addOperators(string num, int target) {
        if (num == "") return {};
        vector<string> res;
        helper_282(res, "", num, target, 0, 0, 0);
        return res;
    }
    void helper_282(vector<string>& res, string path, string num, int target, int pos, long cur, long preval) {
        if (pos == num.length()) {
            if (cur == target) res.push_back(path);
            return;
        }
        for (int i = pos; i < num.length(); i++) {
            if (num[pos] == '0' && i > pos) break; // 105 -> eliminate 1 + 05;
            string sub = num.substr(pos, i - pos + 1);
            long value = stol(sub);
            if (pos == 0) {
                helper_282(res, sub, num, target, i + 1, value, value);
            } else {
                helper_282(res, path + "+" + sub, num, target, i + 1, cur + value, value);
                helper_282(res, path + "-" + sub, num, target, i + 1, cur - value, -value);
                helper_282(res, path + "*" + sub, num, target, i + 1, cur - preval + preval * value, preval * value);
            }
        }
    }
    /*
     *
     *      315. Count of Smaller Numbers After Self
     *
     */
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> arr;
        for (int i = int(nums.size()) - 1; i > -1; i--) {
            res[i] = binarySearch(arr, nums[i]);
        }
        return res;
    }
    int binarySearch(vector<int>& arr, int target) {
        int l = 0, r = int(arr.size());
        while (l < r) {
            int m = l + (r - l) / 2;
            if (arr[m] < target) l = m + 1;
            else r = m;
        }
        arr.insert(arr.begin() + l, target);
        return l;
    }
    /*
     *
     *      65. Valid Number
     *
     */
    bool isNumber(string str) {
        int state = 0, flag = 0;
        while (str[0] == ' ') str.erase(0,1);
        while (str[str.length() - 1] == ' ') str.erase(str.length()-1,1);
        for (int i = 0; i < str.length(); i++) {
            if ('0' <= str[i] && str[i] <= '9') {
                flag = 1;
                if (state <= 2) state = 2;
                else state = (state <= 5) ? 5 : 7;
            } else if ('+' == str[i] || '-' == str[i]) {
                if (state == 0 || state == 3) state++;
                else return false;
            } else if ('.' == str[i]) {
                if (state <= 2) state = 6;
                else return false;
            } else if ('e' == str[i]) {
                if (flag && (state == 2 || state == 6 || state == 7)) state = 3;
                else return false;
            }
            else return false;
        }
        return (state == 2 || state == 5 || (flag && state == 6) || state == 7);
    }
    /*
     *
     *      76. Minimum Window Substring
     *
     */
    string minWindow(string s, string t) {
        int map[128];
        memset(map, 0, sizeof(map));
        for (char c : t) map[c]++;
        int begin = 0, end = 0, counter = int(t.size()), head = 0, subLength = INT_MAX;
        while (end < s.size()) {
            if (map[s[end++]]-- > 0) counter--;
            while (counter == 0) {
                if (end - begin < subLength) {
                    subLength = end - begin;
                    head = begin;
                }
                if (map[s[begin]] == 0) {
                    map[s[begin]]++;
                    counter++;
                    begin++;
                }
            }
        }
        return subLength == INT_MAX ? "" : s.substr(head, subLength);
    }
    /*
     *
     *      135. Candy
     *
     */
    int candy_TLE(vector<int>& ratings) {
        vector<int> tmp(ratings.size(), 0);
        tmp[0] = 1;
        int i = 1, j = 0;
        int total = 1;
        while (i < ratings.size()) {
            if (ratings[i] > ratings[i-1]) {
                tmp[i] = tmp[i-1] + 1;
                j = i;
            } else if (ratings[i] < ratings[i-1]) {
                tmp[i] = 1;
                if (tmp[i-1] == 1) {
                    int k = i;
                    while (k > j) {
                        if ((ratings[k-1] > ratings[k] && tmp[k-1] <= tmp[k]) || (ratings[k-1] > ratings[k] && tmp[k-1] < tmp[k])) {
                            tmp[k-1]++;
                            total++;
                        }
                        k--;
                    }
                }
                
            } else {
                tmp[i] = 1;
            }
            total += tmp[i];
            i++;
        }
        return total;
    }
    int candy(vector<int>& ratings) {
        int size = int(ratings.size());
        if (size <= 1) return size;
        vector<int> tmp(size, 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) tmp[i] = tmp[i-1] + 1;
        }
        for (int i = size - 1; i > 0; i--) {
            if (ratings[i-1] > ratings[i]) tmp[i-1] = max(tmp[i] + 1, tmp[i-1]);
        }
        int result = 0;
        for (int i = 0; i < size; i++) {
            result += tmp[i];
        }
        return result;
    }
    /*
     *
     *      214. Shortest Palindrome
     *
     */
    string shortestPalindrome_TLE(string s) {
        if (s == "") return s;
        int i;
        for (i = int(s.length())-1; i >= 0; i--) {
            if (isParl(s, 0, i)) break;
        }
        string rs = s.substr(i + 1);
        reverse(rs.begin(), rs.end());
        
        return rs + s;
    }
    bool isParl(string s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    string shortestPalindrome(string s) {
        string rs = s;
        reverse(rs.begin(), rs.end());
        string l = s + "#" + rs;
        vector<int> p(l.length(), 0);
        for (int i = 1; i < l.length(); i++) {
            int j = p[i-1];
            while (j > 0 && l[i] != l[j]) j = p[j-1];
            p[i] = j + 1;
        }
        return rs.substr(0, s.length() - p[l.length() - 1]) + s;
    }
    /*
     *
     *      420. Strong Password Checker
     *
     */
    int strongPasswordChecker(string s) {
        int l = int(s.length());
        int deleteTarget = s.length() > 20 ? l - 20 : 0;
        int addTarget = s.length() < 6 ? 6 - l : 0;
        int toDelete = 0, toAdd = 0, toChange = 0, upper = 1, lower = 1, digit = 1;
        
        for (int i = 0, j = 0; i < l; i++) {
            if (isupper(s[i])) upper = 0;
            if (isdigit(s[i])) digit = 0;
            if (islower(s[i])) lower = 0;
            
            if (i - j == 2) {
                if (s[j] == s[j+1] && s[j+1] == s[i]) {
                    if (toAdd < addTarget) {    // for aaa, if toAdd < addTarget, aaa -> aaba, which also increase the length
                        toAdd++;
                        j = i;
                    } else {
                        toChange++;     // for aaa, if toChange < addTarget, aaa -> aab, which also keep the same length
                        j = i + 1;
                    }
                } else j++;
            }
        }
        if (s.length() <= 20) return max(addTarget + toChange, upper + lower + digit);
        toChange = 0;// if tolong, remove aaa-> aa
        vector<unordered_map<int,int>> lenCount(3);
        for (int i = 0, j = 0, len; i <= l; i++) {
            if (i == l || s[j] != s[i]) {
                len = i - j;
                if (len > 2) lenCount[len % 3][len]++;
                j = i;
            }
        }
        for (int i = 0, numLetters, dec; i < 3; i++) {
            for (auto it = lenCount[i].begin(); it != lenCount[i].end(); it++) {
                if (i < 2) {
                    numLetters = i + 1;
                    dec = min(it->second, (deleteTarget - toDelete) / numLetters);
                    toDelete += dec * numLetters;
                    it->second -= dec;
                    if (it->first - numLetters > 2) lenCount[2][it->first - numLetters] += dec;
                }
                toChange += (it->second) * (it->first / 3);
            }
        }
        int dec = (deleteTarget - toDelete) / 3;
        toChange -= dec;
        toDelete -= dec * 3;
        
        return deleteTarget + max(toChange, upper + lower + digit);
    }
    /*
     *
     *      327. Count of Range Sum
     *
     */
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sums (nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            sums[i+1] = sums[i] + nums[i];
        }
        return helper_327(sums, 0, int(sums.size()), lower, upper);
    }
    int helper_327(vector<long>& sums, int start, int end, int lower, int upper) {
        if (end - start <= 1) return 0; // only one number;
        int mid = start + (end - start) / 2;
        int count = helper_327(sums, start, mid, lower, upper) + helper_327(sums, mid, end, lower, upper);
        
        int left = mid, right = mid;
        int index = 0;
        vector<long> cache(end - start, 0);
        
        for (int i = start, j = mid; i < mid; i++) {
            while (left < end && sums[left] - sums[i] < lower) left++;
            while (right < end && sums[right] - sums[i] <= upper) right++;
            while (j < end && sums[i] >= sums[j]) cache[index++] = sums[j++];
            cache[index++] = sums[i];
            count += (right - left);
        }
        
        for (int i = 0; i < index; i++) {
            sums[start + i] = cache[i];
        }
        return count;
    }
    /*
     *
     *      30. Substring with Concatenation of All Words
     *
     */
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> dic;
        int len = int(words[0].length());
        int num = int(words.size());
        for (string word : words) {
            dic[word]++;
        }
        vector<int> res;
        for (int i = 0; i < s.length() - num * len + 1; i++) {
            unordered_map<string, int> window;
            int j = 0;
            while (j < num) {
                string word = s.substr(i + j * len, len);
                if (dic.find(word) != dic.end()) {
                    window[word]++;
                    if (window[word] > dic[word]) break;
                } else break;
                j++;
            }
            if (j == num) res.push_back(i);
            
        }
        return res;
    }
    /*
     *
     *      45. Jump Game II
     *
     */
    int jump_TLE(vector<int>& nums) {
        int count = INT_MAX;
        dfs_45(nums, 0, 0, int(nums.size() - 1), count);
        return count;
    }
    void dfs_45(vector<int>& nums, int start, int steps, int end, int& count) {
        if (start >= end) {
            if (steps < count) count = steps;
            return;
        }
        int total = nums[start];
        for (int j = 1; j <= total; j++) {
            if (steps + 1 >= count) break;
            dfs_45(nums, start + j, steps + 1, end, count);
        }
    }
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int nextMax = 0;
        int curMax = 0;
        int level = 0;
        int i = 0;
        while (curMax - i + 1 > 0) {
            level++;
            while (i <= curMax) {
                nextMax = max(nextMax, nums[i] + i);
                if (nextMax >= nums.size() - 1) return level;
                i++;
            }
            curMax = nextMax;
        }
        return 0;
    }
    /*
     *
     *      296. Best Meeting Point
     *
     */
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> row;
        vector<int> col;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        sort(row.begin(), row.end());
        sort(col.begin(), col.end());
        int r = int(row.size()), c = int(col.size());
        int mid_row = r % 2 ? row[r / 2] : (row[r / 2 - 1] + row[r / 2]) / 2;
        int mid_col = c % 2 ? col[c / 2] : (col[c / 2 - 1] + col[c / 2]) / 2;
        int dis = 0;
        for (int i = 0; i < r; i++) dis += abs(mid_row - row[i]);
        for (int i = 0; i < c; i++) dis += abs(mid_col - col[i]);
        return dis;
    }
    /*
     *
     *      239. Sliding Window Maximum
     *
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
    /*
     *
     *      239. Sliding Window Maximum
     *
     */
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        int l = int(s1.length());
        int count[128] = {0};
        for (int i = 0; i < l; i++) {
            count[s1[i]]++;
            count[s2[i]]--;
        }
        for (int i = 0; i < 128; i++) {
            if (count[i] != 0) return false;
        }
        for (int i = 1; i< l; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) return true;
            if (isScramble(s1.substr(0, i), s2.substr(l - i)) && isScramble(s1.substr(i), s2.substr(0, l - i))) return true;
        }
        return false;
    }
    /*
     *
     *      97. Interleaving String
     *
     */
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) return false;
        bool table[s1.length() + 1][s2.length() + 1];
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) table[i][j] = true;
                else if (i == 0) table[i][j] = table[i][j-1] && (s3[i+j-1] == s2[j-1]);
                else if (j == 0) table[i][j] = table[i-1][j] && (s3[i+j-1] == s1[i-1]);
                else table[i][j] = (table[i-1][j] && (s3[i+j-1] == s1[i-1])) || (table[i][j-1] && (s3[i+j-1] == s2[j-1]));
            }
        }
        return table[s1.length()][s2.length()];
    }
    /*
     *
     *      25. Reverse Nodes in k-Group
     *
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k < 2) return head;
        int count = 0;
        ListNode* cur = head;
        ListNode* preHead = new ListNode(-1);
        preHead->next = head;
        while (cur) {
            count++;
            cur = cur->next;
        }
        
        ListNode* pre = preHead;
        ListNode* next = NULL;
        ListNode* tmp = NULL;
        while (count >= k) {
            cur = pre->next;
            next = cur->next;
            for (int i = 1; i < k; i++) {
                tmp = next->next;
                next->next = pre->next;
                pre->next = next;
                cur->next = tmp;
                next = tmp;
            }
            count -= k;
            pre = cur;
        }
        return preHead->next;
    }
    /*
     *
     *      44. Wildcard Matching
     *
     */
    bool isMatch44(string s, string p) {
        int sl = int(s.length()), pl = int(p.length()), i, j, istar = -1, jstar = -1;
        for (i = 0, j = 0; i < sl; i++, j++) {
            if (p[j] == '*') {
                istar = i;
                jstar = j;
                i--;
            } else {
                if (s[i] != p[j] && p[j] != '?') {
                    if (istar > -1) {
                        i = istar++;
                        j = jstar;
                    } else return false;
                }
            }
        }
        while (p[j] == '*') j++;
        return j == pl;
    }
    /*
     *
     *      32. Longest Valid Parentheses
     *
     */
    int longestValidParentheses(string s) {
        if (s.length() <= 1) return 0;
        int maxLen = 0;
        vector<int> dp(s.length(), 0);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i - 2) >= 0 ? (dp[i-2] + 2) : 2;
                } else {
                    if (i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == '(') {
                        dp[i] = dp[i-1] + 2 + ((i-dp[i-1]-2>=0) ? dp[i-dp[i-1]-2]:0);
                    }
                }
                maxLen = max(maxLen, dp[i]);
            }
        }
        return maxLen;
    }
    /*
     *
     *      174. Dungeon Game
     *
     */
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = int(dungeon.size());
        int n = int(dungeon[0].size());
        
        vector<vector<int>> hp(m+1, vector<int> (n+1, INT_MAX));
        hp[m][n-1] = 1;
        hp[m-1][n] = 1;
        for (int i = m - 1; i > -1; i--) {
            for (int j = n - 1; j > -1; j--) {
                int need = min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j];
                hp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return hp[0][0];
    }
    /*
     *
     *      68. Text Justification
     *
     */
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int start = 0, end = 1, n = int(words.size());
        while (start < n) {
            int space = 1;
            int wordLength = int(words[start].length());
            while (end < n && space + wordLength + words[end].length() <= maxWidth) {
                space++;
                wordLength += words[end].length();
                end++;
            }
            string line = words[start];
            if (end == n) {
                for (int i = start + 1; i < end; i++) line += " " + words[i];
                for (int k = int(line.length()); k < maxWidth; k++) line += " ";
            } else if (end - start == 1) {
                for (int k = int(line.length()); k < maxWidth; k++) line += " ";
            } else {
                int average = (maxWidth - wordLength) / (end - start - 1);
                int remain = (maxWidth - wordLength) % (end - start - 1);
                for (int i = start + 1; i < end; i++) {
                    for (int l = 0; l < average; l++) line += " ";
                    if (remain-- > 0) line += " ";
                    line += words[i];
                }
            }
            result.push_back(line);
            start = end;
            end = end + 1;
        }
        return result;
    }
};
