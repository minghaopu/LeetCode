//
//  Medium.cpp
//  LeetCode
//
//  Created by roneil on 9/20/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class Solution {
public:

    /*
     *
     *      151  Reverse Words in a String
     *
     */
    void reverseWords(string &s) {
        vector<string> stack;
        string newS = "";
        int i, j;
        for (i = 0, j = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (i != j) {
                    stack.push_back(s.substr(j, i - j));
                    j = i + 1;
                }else {
                    j++;
                }
            }
        }
        if (i != j) stack.push_back(s.substr(j, i - j));
        for (i = stack.size() - 1; i > -1 ; i--) {
            newS += stack[i] + ' ';
        }
        s = newS.substr(0, newS.length() - 1);
    }
    /*
     *
     *      3  Longest Substring Without Repeating Characters
     *
     */
    int lengthOfLongestSubstring(string s) {
        int map[128];
        memset(map, -1, sizeof(map));
        int res = 0;
        int cur, last;
        for (cur = 0, last = -1; cur < s.length(); cur++) {
            if (map[s[cur]] > last) last = map[s[cur]];
            map[s[cur]] = cur;
            res = max(res, cur - last);
        }
        if (cur != last) res = max(res, last - cur);
        return res;
    }
    
    /*
     *
     *      5   Longest Palindromic Substring
     *
     */
    string longestPalindrome(string s) {
        int l = s.length();
        int longestBegin = 0;
        int max = 1;
        bool table[1000][1000] = {false};
        for (int i = 0; i < l; i++) {
            table[i][i] = true;
        }
        for (int i = 0; i < l; i++) {
            if (s[i] == s[i+1]) {
                table[i][i+1] = true;
                longestBegin = i;
                max = 2;
            }
        }
        for (int len = 3; len <= l; len++) {
            for (int i = 0; i < l - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && table[i+1][j-1]) {
                    table[i][j] = true;
                    longestBegin = i;
                    max = len;
                }
            }
        }
        return s.substr(longestBegin, max);
    }
    /*
     *
     *      15   3sum
     *
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        int a;
        int b;
        int c;
        int len = nums.size();
        
        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            a = nums[i];
            
            int l = i + 1;
            int r = len - 1;
            while (l < r) {
                b = nums[l];
                c = nums[r];
                if (a + b + c == 0) {
                    vector<int> temp = {a, b, c};
                    result.push_back(temp);
                    while (nums[l]==nums[l+1]) l++;
                    while (nums[r]==nums[r-1]) r--;
                    l++;
                    r--;
                } else if (a + b + c < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return result;
    }
    
    /*
     *
     *      148     Sort List
     *
     */
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* h2 = slow->next;
        slow->next = NULL;
        return mergeList(sortList(head),sortList(h2));
    }
    ListNode* mergeList(ListNode* h1, ListNode* h2) {
        ListNode* newHead = new ListNode(0);
        ListNode* n = newHead;
        while (h1 != NULL && h2 != NULL) {
            if (h1->val < h2->val) {
                n->next = h1;
                h1 = h1->next;
            } else {
                n->next = h2;
                h2 = h2->next;
            }
            n = n->next;
        }
        if (h1 != NULL) {
            n->next = h1;
        }
        if (h2 != NULL) {
            n->next = h2;
        }
        return newHead->next;
    }
    
    /*
     *
     *      53     Maximum Subarray
     *
     */
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, sum);
            sum = max(0, sum);
        }
        return ans;
    }
    /*
     *
     *      139. Word Break
     *
     */
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (wordDict.size() == 0) return false;
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= s.length(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j]) {
                    string sub = s.substr(j, i - j);
                    if (wordDict.find(sub) != wordDict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[s.length()];
    }
    /*
     *
     *      11. Container With Most Water
     *
     */
    int maxArea(vector<int>& height) {
        int water = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            int h = min(height[r], height[l]);
            water = max(water, h * (r - l));
            while (height[l] <= h && l < r) l++;    // <= means l++ will stop if find a larger height than h
            while (height[r] <= h && l < r) r--;
        }
        return water;
    }
    /*
     *
     *      153. Find Minimum in Rotated Sorted Array
     *
     */
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = (end - start)/2;
            if (nums[mid] < nums[end]) end = mid;
            else start = mid + 1;
        }
        return nums[start];
    }
    /*
     *
     *      150. Evaluate Reverse Polish Notation
     *
     */
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for (int i = 0; i < tokens.size(); i++) {
            string t = tokens[i];
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                if(t=="+") s.push(op1 + op2);
                else if(t=="-") s.push(op2 - op1);
                else if(t=="*") s.push(op1 * op2);
                else if(t=="/") s.push(op2 / op1);
            } else {
                s.push(atoi(t.c_str()));
            }
        }
        return s.top();
    }
    /*
     *
     *      49. Group Anagrams
     *
     */
    string countSortString(string& s) {
        int c[26] = {0}, len = s.length();
        for (int i = 0; i < len; i++) {
            c[s[i] - 'a']++;
        }
        string sortedString = "";
        for (int i = 0; i < 26; i++) {
            for (int j = c[i]; j > 0; j--) {
                sortedString += char('a' + i);
            }
        }
        return sortedString;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> hash;
        for (int i = 0; i < strs.size(); i++) {
            string temp = countSortString(strs[i]);
            hash[temp].push_back(strs[i]);
        }
        for (auto it:hash) {
            result.push_back(it.second);
        }
        return result;
    }
    /*
     *
     *      122. Best Time to Buy and Sell Stock II
     *
     */
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) return 0;
        int max = 0;
        for (int i = 1; i < len; i++) {
            max += prices[i] > prices[i-1]?prices[i] - prices[i-1]:0;
        }
        return max;
    }
    /*
     *
     *      17. Letter Combinations of a Phone Number
     *
     */
    vector<string> letterCombinations(string digits) {
        vector<string> board = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        if (digits.length() == 0) {
            return result;
        }
        result.push_back("");
        for (int i = 0; i < digits.length(); i++) {
            int num = digits[i] - '0';
            string add = board[num];
            if (add == "") {
                continue;
            }
            vector<string> tmp;
            for (int j = 0; j < result.size(); j++) {
                for (int k = 0; k < add.length(); k++) {
                    tmp.push_back(result[j] + add[k]);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
    /*
     *
     *      152. Maximum Product Subarray
     *
     */
//    Fist we assume there is no zero in the A[]. The answer must be A[0] A[1] .... A[i] OR A[j] *A[j+1] A[n - 1]. (Try to prove yourself)
//    
//    Then when we have zero in the A[] (assum A[k] == 0). We could see A[0],A[1]...A[k - 1 ] As An Array and A[k + 1] A[k + 2]...A[n-1] is another.
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        int result = INT_MIN;
        for (int i = 0, frontproduct = 1, backproduct = 1; i < len; i++) {
            frontproduct *= nums[i];
            backproduct *= nums[len - i - 1];
            result = max(result, max(frontproduct, backproduct));
            if (frontproduct == 0) frontproduct = 1;
            if (backproduct == 0) backproduct = 1;
        }
        return result;
    }
    /*
     *
     *      179. Largest Number
     *
     */
    static bool compareString(int a, int b) {
        string str_a = to_string(a);
        string str_b = to_string(b);
        return str_a + str_b > str_b + str_b;                   // descending
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compareString);
        string res = "";
        for (int i = 0; i < nums.size(); i++) {
            res += nums[i];
        }
        return res[0] == '0'?"0":res;
    }
    unsigned long getNumberLength(int num) {
        return to_string(num).length();
    }
    /*
     *
     *      127. Word Ladder
     *
     */
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        wordList.erase(beginWord);
        int dist = 2;
        while (!q.empty()) {
            int l = q.size();
            for (int i = 0; i < l; i++) {
                beginWord = q.front();
                q.pop();
                for (int i = 0; i < beginWord.length(); i++) {
                    string tmp = beginWord;
                    for (int j = 0; j < 26; j++) {
                        tmp[i] = 'a' + j;
                        if (tmp == endWord) return dist;
                        if (tmp != beginWord && wordList.find(tmp) != wordList.end()) {
                            q.push(tmp);
                            wordList.erase(tmp);
                        }
                    }
                }
                
            }
            dist++;
        }
        return 0;
    }
    /*
     *
     *      12. Integer to Roman
     *
     */
    string intToRoman(int num) {
        string M[4] = {"", "M", "MM", "MMM"};
        string I[10] = {"","I","II","III","IV","V", "VI", "VII", "VIII", "IX"};
        string X[10] = {"","X","XX","XXX","XL","L", "LX", "LXX", "LXXX", "XC"};
        string C[10] = {"","C","CC","CCC","DC","D", "DC", "DCC", "DCCC", "CM"};
        return  M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[(num%10)];
    }
    /*
     *
     *      79. Word Search
     *
     */
    static bool isFound(vector<vector<char>>& board, string word,int start, int x, int y, int m, int n) {
        if (start == word.length()) {
            return true;
        }
        if (x < 0 || y < 0 || x >= m || y >= n) {
            return false;
        }
        
        char t = board[x][y];
        bool res = false;
        if (t != word[start] || t == '*') return false;
        
        board[x][y] = '*';
        if (!res) res = isFound(board, word, start+1, x-1, y, m, n);
        if (!res) res = isFound(board, word, start+1, x, y-1, m, n);
        if (!res) res = isFound(board, word, start+1, x+1, y, m, n);
        if (!res) res = isFound(board, word, start+1, x, y+1, m, n);
        
        board[x][y] = t;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isFound(board, word.c_str(), 0, i, j, m, n)) return true;
            }
        }
        return false;
        
    }
    /*
     *
     *      49. Permutation;
     *
     */
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res, nums, 0, nums.size());
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& nums, int start, int length) {
        if (start == length) {
            res.push_back(nums);
        }else {
            for (int i = start; i < length; i++) {
                swap(nums[i], nums[start]);
                dfs(res, nums, start + 1, length);
                swap(nums[i], nums[start]);
            }
        }
    }
    /*
     *
     *      54. Spiral Matrix
     *
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        res.resize(m*n);
        int a = 0, b = 0, c = m - 1, d = n - 1, i = 0;
        while (true) {
            //right
            for (int col = b; col <= d; col++) res[i++] = matrix[a][col];
            if (++a > c) break;
            //down
            for (int row = a; row <= c; row++) res[i++] = matrix[row][d];
            if (--d < b) break;
            //left
            for (int col = d; col >= b; col--) res[i++] = matrix[c][col];
            if (--c < a) break;
            //up
            for (int row = c; row >= a; row--) res[i++] = matrix[row][b];
            if (++b > d) break;
        }
        return res;
    }
    /*
     *
     *      22. Generate Parentheses
     *
     */
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs_Parenthesis(res, "", n, 0);
        return res;
    }
    void dfs_Parenthesis(vector<string>& res, string str, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(str);
            return;
        }
        if (right > 0) dfs_Parenthesis(res, str + ')', left, right - 1);
        if (left > 0) dfs_Parenthesis(res, str + '(', left - 1, right + 1);
    }
    /*
     *
     *      142. Linked List Cycle II
     *
     */
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        return NULL;
    }
    /*
     *
     *      200. Number of Islands
     *
     */
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '1') continue;
                else {
                    res++;
                    expand(grid, i, j, m, n);
                }
            }
        }
        return res;
    }
    void expand(vector<vector<char>>& grid, int x, int y, int m, int n) {
        grid[x][y] = '*';
        if (x < m - 1 && grid[x + 1][y] == '1') expand(grid, x + 1, y, m, n);
        if (y < n - 1 && grid[x][y + 1] == '1') expand(grid, x, y + 1, m, n);
        if (y > 0 && grid[x][y - 1] == '1') expand(grid, x, y - 1, m, n);
        if (x > 0 && grid[x - 1][y] == '1') expand(grid, x - 1, y, m, n);
    }
    /*
     *
     *     48. rotate image
     *
     */
    void rotateImage(vector<vector<int>>& matrix) {
        int l = matrix.size();
        vector<vector<int>> res;
        if (l == 0) return;
        res.resize(l);
        for (int i = 0; i < l; i++) {
            res[i].resize(l);
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                res[j][l - 1 - i] = matrix[i][j];
            }
        }
        matrix = res;
    }
    void rotateImageInPlace(vector<vector<int>>& matrix) {
        int l = matrix.size();
        if (l == 0) return;
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l - j - 1; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[i][l - j - 1];
                matrix[i][l - j - 1] = t;
            }
        }
    }
    /*
     *
     *      96. Unique Binary Search Trees
     *
     */
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
    /*
     *
     *      147. Insertion Sort List
     *
     */
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return head;
        ListNode* new_head = new ListNode(0);
        ListNode* cur = head;
        ListNode* pre = new_head;
        ListNode* next = NULL;
        while (cur != NULL) {
            next = cur->next;
            while (pre->next != NULL && pre->next->val < cur->val) {
                pre = pre->next;
            }
            cur->next = pre->next;
            pre->next = cur;
            cur = next;
            pre = new_head;
        }
        return new_head->next;
    }
    /*
     *
     *      SJF Shorted Job First
     *
     */
    float SJF(vector<int>& request, vector<int>& duration) {
        int nowTime = 0;
        int length = request.size();
//        vector<int> start(length,0);
        
        int nextIndex;
        int sum = 0;

        while (!request.empty()) {
            vector<int> queue;
            findIndex(request, queue, nowTime);
            nextIndex = findNextDuration(duration, queue);
            sum += nowTime - request[nextIndex];
            nowTime += duration[nextIndex];
            request.erase(request.begin() + nextIndex);
            duration.erase(duration.begin() + nextIndex);
        }
        return (float)sum / (float)length;
    }
    void findIndex(vector<int>& crequest, vector<int>& queue, int nowTime) {
        for (int i = 0; i < crequest.size(); i++) {
            if (crequest[i] <= nowTime) queue.push_back(i);
        }
    }
    int findNextDuration(vector<int>& duration, vector<int>& queue) {
        int minDuration = INT_MAX;
        int minIndex = -1;
        for (int i = 0; i < queue.size(); i++) {
            if (duration[queue[i]] < minDuration) {
                minIndex = queue[i];
                minDuration = duration[minIndex];
            }
        }
        return minIndex;
    }
    /*
     *
     *      Round Robin Average Wait Time
     *
     */
    float rrAvgWaitTime(vector<int>& request, vector<int>& duration, int quantum) {
        
        int num = duration.size();
        vector<int> start(1,0);
        int i = 1;
        while(i < duration.size()) {
            if (duration[i - 1] > quantum) {
                start.push_back(start[i-1] + quantum);
                duration.push_back(duration[i - 1] - quantum);
                request.push_back(start.back());
            } else {
                start.push_back(start[i - 1] + duration[i - 1]);
            }
            i++;
        }
        int sum = 0;
        for (int i = 1; i < start.size(); i++) {
            sum += start[i] - request[i];
        }
        return (float)sum/(float)num;
    }
    /*
     *
     *      91. Decode Ways
     *
     */
    int numDecodings(string s) {        //3ms
        int l = s.length();
        if (l == 0 || s[0] == '0') return 0;
        vector<int> dp(l, 0);
        dp[0] = 1;
        if (l >= 2) {
            if (s[0] > '2' && s[1] == '0') dp[1] = 0;
            else dp[1] = ((s[0] == '1' && s[1] != '0')|| (s[0] == '2' && s[1] < '7' && s[1] > '0')) ? 2 : 1;
        }
        for (int i = 2; i < l; i++) {
            if(s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') dp[i] = dp[i - 2];
                else return 0;
            }
            else dp[i] = dp[i - 1] + ((s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')) ? dp[i - 2]:0);
        }
        return dp[l-1];
    }
    int numDecodings_2(string s) {          // 0ms
        if (s.length() == 0 || s.front() == '0') return 0;
        int r1 = 1, r2 = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '0') r1 = 0;
            
            if (s[i - 1] == '1' ||(s[i] < '7' && s[i - 1] == '2')) {
                r1 = r1 + r2;
                r2 = r1 - r2;
            } else {
                r2 = r1;
            }
        }
        return r1;
    }
    /*
     *
     *      228. Summary Ranges
     *
     */
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() == 0) return res;
        res.resize(nums.size());
        string str;
        string to = "->";
        long long start = nums[0];
        long long end = start;
        int k = 0;
        nums.push_back(start);
        for (int i = 1; i < nums.size(); i++) {
            if (end + 1 == nums[i]) {
                end = nums[i];
            } else {
                str = "";
                if (start == end) {
                    str += to_string(start);
                } else {
                    str += to_string(start) + to + to_string(end);
                }
                res[k] = str;
                k++;
                start = nums[i];
                end = start;
            }
        }
        res.resize(k);
        return res;
    }
    /*
     *
     *      238. Product of Array Except Self
     *
     */
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = nums.size();
        vector<int>res(l,1);
        for (int i = 1; i < l; i++) {
            res[i] = res[i-1] * nums[i-1];
        }
        vector<int>right(l,1);
        for (int i = l - 2; i > -1; i--) {
            right[i] = right[i+1] * nums[i+1];
            res[i] *= right[i];
        }
        return res;
    }
    /*
     *
     *      143. Reorder List && Reverse List
     *
     */
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur != NULL) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        ListNode* cur = head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* mid;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) {
            mid = slow->next;
        } else {
            mid = slow;
        }
        ListNode* back = reverseList(mid);
        if (fast) {
            slow->next = back;
        } else {
            slow = back;
        }
        while (back && cur->next != back) {
            ListNode* aNext = cur->next;
            ListNode* bNext = back->next;
            back->next = cur->next;
            cur->next = back;
            cur = aNext;
            back = bNext;
        }
        if (back == NULL) cur->next = NULL;
    }
    /*
     *
     *      16. 3Sum Closest
     *
     */
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        int closet = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int first = 0; first < size - 2; first++) {
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            int second = first + 1;
            int third = size - 1;
            while (second < third) {
                int curSum = nums[first] + nums[second] + nums[third];
                if (curSum == target) return curSum;
                if (abs(curSum - target) < abs(closet - target)) closet = curSum;
                if (curSum > target) {
                    third--;
                } else {
                    second++;
                }
            }
        }
        return closet;
    }
    /*
     *
     *      43. Multiply Strings
     *
     */
    string multiply(string num1, string num2) {
        int l1 = num1.length();
        int l2 = num2.length();
        string s(l1 + l2, '0');
        for (int i = l1 - 1; i > -1; i--) {
            int carry = 0;
            for (int j = l2 - 1; j > -1; j--) {
                int tmp = (num1[i] - '0') * (num2[j] - '0') + (s[i + j + 1] - '0') + carry;
                s[i + j + 1] = '0' + tmp % 10;
                carry = tmp / 10;
            }
            s[i] += carry;
        }
        int start = 0;
        while (start < l1 + l2 - 1) {
            if (s[start] != '0') break;
            start++;
        }
        return s.substr(start);
    }
    /*
     *
     *     116. Populating Next Right Pointers in Each Node
     *
     */
    void connect_LessEfficient(TreeLinkNode *root) {
        if (root == NULL) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            queue<TreeLinkNode*> nextLevel;
            TreeLinkNode* pre = q.front();
            if (pre->left != NULL) {
                nextLevel.push(pre->left);
                nextLevel.push(pre->right);
            }
            q.pop();
            TreeLinkNode* cur = NULL;
            while (!q.empty()) {
                cur = q.front();
                if (cur->left != NULL) {
                    nextLevel.push(cur->left);
                    nextLevel.push(cur->right);
                }
                pre->next = cur;
                pre = cur;
                q.pop();
            }
            pre->next = NULL;
            swap(q, nextLevel);
        }
    }
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        TreeLinkNode* pre = root;
        TreeLinkNode* cur = NULL;
        while (pre->left) {
            cur = pre;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next != NULL) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;
        }
    }
    /*
     *
     *     98. Validate Binary Search Tree
     *
     */
    bool isValidBST(TreeNode* root) {
        return isSubTreeValid(root, NULL, NULL);
    }
    bool isSubTreeValid(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == NULL) return true;
        if ((min && root->val <= min->val) || (max && root->val >= max->val)) return false;
        return isSubTreeValid(root->left, min, root) && isSubTreeValid(root->right, root, max);
    }
    /*
     *
     *     162. Find Peak Element
     *
     */
    vector<int> findAllPeakElements(vector<int>& nums) {
        int l = nums.size();
        vector<int> res;
        if (l == 1) {
            res.push_back(0);
            return res;
        }
        
        int left = 0;
        while (left <= l - 2) {
            int start = left + 1;
            if (start == l - 1) {
                if (nums[left] < nums[start]) {
                    res.push_back(start);
                } else {
                    res.push_back(left);
                };
                left++;
            } else {
                if (nums[left] < nums[start]) {
                    if (nums[start] < nums[start + 1]) {
                        left++;
                    }
                    else {
                        res.push_back(start);
                        left+=2;
                    }
                } else {
                    res.push_back(left);
                    left++;
                }
            }
            
        }
        return res;
    }
    int findPeakElement(vector<int>& nums) {
        int l = nums.size();
        int left = 0;
        while (left <= l - 2) {
            int start = left + 1;
            if (start == l - 1) {
                if (nums[left] < nums[start]) {
                    return start;
                } else {
                    return left;
                };
            } else {
                if (nums[left] < nums[start]) {
                    if (nums[start] < nums[start + 1]) {
                        left++;
                    }
                    else {
                        return start;
                    }
                } else {
                    return left;
                }
            }
            
        }
        return 0;
    }
    /*
     *
     *     75. Sort Colors
     *
     */
    void sortColors(vector<int>& nums) {
        int map[3] = {0,0,0};
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        int i = 0;
        int total = 0;
        int j = 0;
        while (j < 3) {
            if (i < map[j]) {
                nums[total] = j;
                total++;
                i++;
            } else {
                j++;
                i = 0;
            }
            
        }
    }
    /*
     *
     *     55. Jump Game
     *
     */
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        int i = 0;
        while(i <= maxIndex && i < nums.size()) {
            int t = nums[i] + i;
            if (t >= maxIndex) maxIndex = t;
            i++;
        }
        return maxIndex >= nums.size() - 1;
    }
    /*
     *
     *     120. Triangle
     *
     */
    int minimumTotal(vector<vector<int>>& triangle) {
        int l = triangle.size();
        vector<int> minlen(triangle.back());                //all the shortest path sum at kth level
        for (int level = l - 2; level > -1; level--) {
            for (int i = 0; i <= level; i++) {
                minlen[i] = min(minlen[i], minlen[i+1]) + triangle[level][i];
            }
        }
        return minlen[0];
    }
    /*
     *
     *     134. Gas Station
     *
     */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int l = gas.size();
        int tank = 0;
        int subsum = INT_MAX;
        for (int i = 0; i < l; i++) {
            tank += gas[i] - cost[i];
            if (tank < subsum) {
                subsum = tank;
                start = i + 1;
            }
        }
        return tank < 0? -1: (start%l);
    }
    /*
     *
     *     39. Combination Sum
     *
     */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); i++) {
            if (i > 0 && candidates[i] == candidates[i-1]) continue;
            vector<int> row = {candidates[i]};
            findRest(res, candidates, target - candidates[i], row, i);
        }
        return res;
    }
    void findRest(vector<vector<int>> & res, vector<int>& candidates, int target, vector<int>& row, int start) {
        if (target == 0) res.push_back(row);
        if (target <  candidates[start]) return;
        else {
            for (int i = start; i < candidates.size(); i++) {
                int t = target - candidates[i];
                row.push_back(candidates[i]);
                findRest(res, candidates, t, row, i);
                row.pop_back();
            }
        }
    }
    /*
     *
     *     187. Repeated DNA Sequences
     *
     */
    
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hash;
        vector<string> res;
        for (int i = 0; i < s.length() - 9; i++) {
            string t = s.substr(i, 10);
            if (hash.find(t) == hash.end()) hash[t] = 1;
            else hash[t]++;
        }
        for (auto it = hash.begin(); it != hash.end(); it++) {
            if (it->second > 1) res.push_back(it->first);
        }
        return res;
    }
    /*
     *
     *     31. Next Permutation
     *
     */
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i > -1 && nums[i] >= nums[i + 1]) {
            i--;
        }
        reverse(nums.begin() + i + 1, nums.end());
        
        if (i == -1) return;
        int index;
        for (index = i+1; index < nums.size(); index++) {
            if (nums[index] > nums[i]) break;
        }
        swap(nums[index],nums[i]);
    }
    /*
     *
     *     62. Unique Paths
     *
     */
    int uniquePaths(int m, int n) {
        int map[m][n];
        map[0][0] = 1;
        for (int i = 0; i < m; i++) {
            map[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            map[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                map[i][j] = map[i-1][j] + map[i][j-1];
            }
        }
        return map[m-1][n-1];
    }
    /*
     *
     *     78. Subsets
     *
     */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1, vector<int>());
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int n = res.size();
            for (int j = 0; j < n; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
    /*
     *
     *     220. Contains Duplicate III
     *
     */
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0 || nums.size() < 2) return false;
        auto size = nums.size();
        set<int> rec;
        for (int i = 0; i < size; i++) {
            
            if (i > k) rec.erase(nums[i - k - 1]);
            long long a = nums[i];
            set<int>::iterator it = rec.lower_bound(nums[i] - t);
            if (it != rec.end() && abs(nums[i] - *it) <= t) return true;
            rec.insert(nums[i]);
        }
        return false;
    }
    /*
     *
     *     18. 4Sum
     *
     */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        auto size = nums.size();
        if (size < 4) return res;
        for (int i = 0; i < size - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < size - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1;
                int l = size - 1;
                while (k < l) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum > target) l--;
                    else if (sum < target) k++;
                    else {
                        res.push_back(vector<int> {nums[i], nums[j], nums[k], nums[l]});
                        while (nums[k] == nums[k+1]) k++;
                        while (nums[l] == nums[l-1]) l--;
                        k++;
                        l--;
                    }
                }
            }
        }
        return res;
    }
    /*
     *
     *     268. Missing Number
     *
     */
    int missingNumber(vector<int>& nums) {
        // int start = 0;
        int num = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            // num ^= i;
            // start ^= nums[i];
            num ^= i ^ nums[i];
        }
        // return start ^ num;
        return num;
    }
    /*
     *
     *     34. Search for a Range
     *
     */
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();
        int mid;
        while (start < end) {
            mid = (start + end) / 2;
            if (nums[mid] >= target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        int left = start;
        start = 0;
        end = nums.size();
        while (start < end) {
            mid = (start + end) / 2;
            if (nums[mid] <= target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        int right = start;
        return left == right? vector<int> {-1, -1}:vector<int> {left, right -1};
    }
    /*
     *
     *     236. Lowest Common Ancestor of a Binary Tree
     *
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : (!right ? left : root);
    }
    /*
     *
     *     73. Set Matrix Zeroes
     *
     */
    void setZeroes(vector<vector<int>>& matrix) {
        auto m = matrix.size();
        if (m == 0) return;
        auto n = matrix[0].size();
        bool col = false, row = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) row = true;
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for (int i = m - 1; i > -1; i--) {
            for (int j = n - 1; j > 0; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
            if (row) matrix[i][0] = 0;
        }
    }
    /*
     *
     *     108. Convert Sorted Array to Binary Search Tree
     *
     */
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     * };
     */

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return createTree(nums, 0, nums.size() - 1);
    }
    TreeNode* createTree(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        if (start == end) return new TreeNode(nums[start]);
        int rootIndex = ceil((end - start) / 2) + start;
        TreeNode* root = new TreeNode(nums[rootIndex]);
        root->left = createTree(nums, start, rootIndex - 1);
        root->right = createTree(nums, rootIndex + 1, end);
        return root;
    }
    /*
     *
     *     89. Gray Code
     *
     */
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
        for (int i = 1; i <= n; i++) {
            vector<int> tmp = res;
            reverse(tmp.begin(), tmp.end());
            int l = pow(2, i);
            int half = l / 2;
            res.resize(l);
            for (int j = 0; j < half; j++) {
                res[j + half] = tmp[j] ^ half;
            }
        }
        return res;
    }
};
