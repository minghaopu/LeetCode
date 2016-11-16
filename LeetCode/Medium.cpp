//
//  Medium.cpp
//  LeetCode
//
//  Created by roneil on 9/20/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
//bool sorTopKFrequent(pair<int, int> a, pair<int, int> b) {
//    return a.second < b.second;
//}
class Solution {
private:
    
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
    /*
     *
     *     144. Binary Tree Preorder Traversal
     *
     */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* tmp = s.top();
            s.pop();
            res.push_back(tmp->val);
            if (tmp->right != NULL) s.push(tmp->right);
            if (tmp->left != NULL) s.push(tmp->left);
        }
        return res;
    }
    /*
     *
     *     94. Binary Tree Inorder Traversal
     *
     */

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* tmp = s.top();
            if (tmp->left != NULL) {
                s.push(tmp->left);
                tmp->left = NULL;
            } else {
                res.push_back(tmp->val);
                s.pop();
                if (tmp->right != NULL) s.push(tmp->right);
            }
        }
        return res;
    }
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                TreeNode* top = s.top();
                res.push_back(top->val);
                s.pop();
                if (top->right) {
                    cur = top->right;
                }
            }
        }
        return res;
    }
    /*
     *
     *     145. Binary Tree Postorder Traversal
     *
     */
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* last = NULL;
        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                TreeNode* top = s.top();
                if (top->right && top->right != last) {
                    cur = top->right;
                } else {
                    res.push_back(top->val);
                    s.pop();
                    last = top;
                }
            }
        }
        return res;
    }
    /*
     *
     *     215. Kth Largest Element in an Array
     *
     */
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int p = partition(nums, left, right);
            if (p == k - 1) return nums[p];
            else if (p < k - 1) left = p + 1;
            else right = p - 1;
        }
        return -1;
    }
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++;
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
    /*
     *
     *     166. Fraction to Recurring Decimal
     *
     */
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res = "";
        if (numerator < 0 ^ denominator < 0) res += '-';
        long nn = abs((long)numerator);
        long dd = abs((long)denominator);
        long integral = nn / dd;
        res += to_string(integral);
        long rmd = nn % dd;
        if (rmd == 0) return res;
        res += '.';
        rmd *= 10;
        unordered_map<long, int> hash;
        while (rmd) {
            if (hash.find(rmd) != hash.end()) {
                res.insert(hash[rmd], 1, '(');
                res += ')';
                break;
            }
            long q = rmd / dd;
            hash[rmd] = res.length();
            res += to_string(q);
            rmd = (rmd % dd) * 10;
        }
        
        return res;
    }
    /*
     *
     *     61. Rotate List
     *
     */
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        int count = 1;
        ListNode* last = head;
        while (last->next) {
            count++;
            last = last->next;
        };
        if (count == 1) return head;
        k = count - (k % count);
        while (k) {
            ListNode* t = head;
            head = head->next;
            last->next = t;
            t->next = NULL;
            last = t;
            k--;
        }
        return head;
    }
    ListNode* rotateRight2(ListNode* head, int k) {
        if (head == NULL) return head;
        int count = 1;
        ListNode* last = head;
        while (last->next) {
            count++;
            last = last->next;
        };
        last->next = head;
        k = k % count;
        if (k) {
            for (int i = 0; i < count - k; i++) last = last->next;
        }
        ListNode* newHead = last->next;
        last->next = NULL;
        return newHead;
    }
    /*
     *
     *     35. Search Insert Position
     *
     */
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l <= r) {
            mid = (r - l) / 2 + l;
            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
    /*
     *
     *     338. Counting Bits
     *
     */
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; i++) res[i] = res[i & (i - 1)] + 1;
        return res;
    }
    /*
     *
     *     64. Minimum Path Sum
     *
     */
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        vector<vector<int>> res (m, vector<int> (n, 0));
        res[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j > 0) res[0][j] = grid[0][j] + res[0][j-1];
                else if (j == 0) res[i][0] = grid[i][0] + res[i-1][0];
                else res[i][j] = min(res[i][j-1], res[i-1][j]) + grid[i][j];
            }
        }
        return res[m-1][n-1];
    }
    /*
     *
     *     114. Flatten Binary Tree to Linked List
     *
     */
    void flatten(TreeNode* root) {              // O(n) time & O(n) space
        if (root == NULL) return;
        TreeNode* ptr = new TreeNode(0);
        TreeNode* newRoot = ptr;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* top = s.top();
            ptr->right = new TreeNode(top->val);
            ptr = ptr->right;
            s.pop();
            if (top->right) s.push(top->right);
            if (top->left) s.push(top->left);
        }
        root->left = NULL;
        root->right = newRoot->right->right;
    }
    void flatten2(TreeNode* root) {             // O(n) time & O(1) space
        TreeNode* now = root;
        while (now) {
            if (now->left) {
                TreeNode* pre = now->left;
                while (pre->right) {
                    pre = pre->right;
                }
                pre->right = now->right;
                now->right = now->left;
                now->left = NULL;
            }
            now = now->right;
        }
    }
    /*
     *
     *     92. Reverse Linked List II
     *
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode* newHead = new ListNode(0);
        ListNode* pre = newHead;
        ListNode* p = head;
        ListNode *next, *pm, *prem;
        for (int i = 1; i < m; i++) {
            pre->next = p;
            pre = p;
            p = p->next;
        }
        prem = pre;
        pm = p;
        for (int i = m; i < n; i++) {
            next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        pm->next = p->next;
        p->next = pre;
        prem->next = p;
        return newHead->next;
    }
    /*
     *
     *     71. Simplify Path
     *
     */
    string simplifyPath(string path) {
        string res = "", token;
        stringstream ss (path);
        vector<string> tokens;
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") continue;
            if (token == "..") {
                if (tokens.size() != 0) tokens.pop_back();
            }
            else tokens.push_back(token);
        }
        if (tokens.size() == 0) return "/";
        for (int i = 0; i < tokens.size(); i++) {
            res += "/" + tokens[i];
        }
        return res;
    }
    /*
     *
     *     google oa
     *
     */
    int googleOA1(int X) {
        string s = to_string(X);
        int maxNum = 0;
        if (s.length() < 2) return X;
        for (auto i = 0; i < (int)s.length() - 1; i++) {
            string t = s;
            float sum = (t[i] - '0') + (t[i + 1] - '0');
            int half = ceil(sum / 2);
            t[i+1] = char('0'+half);
            t.erase(i,1);
            maxNum = max(maxNum, stoi(t));
        }
        return maxNum;
    }
    int googleOA2(string &S) {
        string token;
        stack<int> len;
        int res = 0, level = 0, count = 0;
        stringstream ss(S);
        while (getline(ss, token)) {
            count = 0;
            while (token[count] == ' ') count++;
            while (level > count) {
                level--;
                len.pop();
            }
            if (token.find('.') != string::npos) {
                string ext1 = token.substr(token.length() - 4);
                string ext2 = token.substr(token.length() - 5);
                if (ext1 == ".png" || ext1 == ".gif" || ext2 == ".jpeg") {
                    // is pic;
                    int tmp = 0;
                    if (level > 0) tmp += len.top() + level;
                    else tmp = 1;
                    res = max(res, tmp);
                }

            } else {
                // is dir
                if (level > 0) len.push(len.top() + token.length() - count);
                else len.push(token.length() - count);
                level++;
            }
        }
        return res;
    }
    /*
     *
     *     388. Longest Absolute File Path
     *
     */
    int lengthLongestPath(string input) {
        input += '\n';
        stack<int> len;
        string token;
        int res = 0;
        int level = 0;
        int count = 0;
        bool isFile = false;
        for (int i = 0; i < input.length(); i++) {
            char c = input[i];
            if (c == '\t') {
                count++;
            } else if (c == '\n') {
                if (level > count){
                    while (level != count) {
                        len.pop();
                        level--;
                    }
                }
                if (isFile) {
                    int tmp = 0;
                    if (level > 0) tmp += len.top();
                    tmp += token.length() + level;
                    res = res > tmp ? res : tmp;
                    isFile = false;
                } else {
                    
                    if (level > 0) len.push(len.top() + token.length());
                    else len.push(token.length());
                    level++;
                }
                token = "";
                count = 0;
            } else {
                if (c == '.') isFile = true;
                token += c;
            }
        }
        return res;
    }
    int lengthLongestPath2(string input) {
        input += '\n';
        stack<int> len;
        string token;
        int res = 0;
        int level = 0;
        int count = 0;
        bool isFile = false;
        stringstream ss(input);
        while (getline(ss, token)) {
            count = 0;
            while (token[count] == ' ') count++;
            while (level > count) {
                len.pop();
                level--;
            }
            if (token.find_last_of('.') != string::npos) {
                int tmp = 0;
                if (level > 0) tmp += len.top();
                tmp += token.length();
                res = max(res,tmp);
            } else {
                // dir
                if (level > 0) len.push(len.top() + token.length() - count);
                else len.push(token.length());
                level++;
            }
        }
        return res;
    }
    /*
     *
     *     74. Search a 2D Matrix
     *
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;
        int mid, row;
        if (r == -1) return false;
        while (l <= r) {
            mid = (r - l) / 2 + l;
            if (matrix[mid][0] < target) l = mid + 1;
            else r = mid - 1;
        }
        if (l >= matrix.size()) l--;
        if (matrix[l][0] > target) l--;
        if (l == -1) return false;
        row = l;
        l = 0;
        r = matrix[0].size() - 1;
        while (l <= r) {
            mid = (r - l) / 2 + l;
            if (matrix[row][mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return matrix[row][l] == target;
    }
    /*
     *
     *     105. Construct Binary Tree from Preorder and Inorder Traversal
     *
     */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inHash;
        int i;
        for (i = 0; i < preorder.size(); i++) {
            inHash[inorder[i]] = i;
        }
        return createTree(preorder, inHash, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* createTree(vector<int>& preorder, unordered_map<int, int>& inHash, int pstart, int pend, int istart, int iend) {
        if (pstart > pend || istart > iend) return NULL;
        int rootVal = preorder[pstart];
        TreeNode* root = new TreeNode(rootVal);
        
        if (inHash.find(rootVal) != inHash.end()) {
            int iroot = inHash[rootVal];
            root->left = createTree(preorder, inHash, pstart + 1, pstart + iroot - istart, istart, iroot);
            root->right = createTree(preorder, inHash, pstart + iroot - istart + 1, pend, iroot + 1, iend);
        }
        return root;
        
    }
    /*
     *
     *     279. Perfect Squares
     *
     */
    int numSquares(int n) {
        unordered_map<int,int> hash;
        for (int i = 0; i * i <= n; i++) {
            hash[i * i] = 1;
        }
        return findMinLeng(n, hash);
    }
    int findMinLeng(int n, unordered_map<int,int>& hash){
        if (hash.find(n) != hash.end()) return hash[n];
        int root = 1;
        int minLength = INT_MAX;
        while (n >= root * root) {
            root++;
        }
        for (int i = 1; i < root; i++) {
            int res = n - i * i;
            minLength = min(findMinLeng(res,hash), minLength);
        }
        minLength+=1;
        hash[n] = minLength;
        return minLength;
    }
    /*
     *
     *     279. Perfect Squares math solution`
     *
     */
    int numSquares2(int n) {
        while (n % 4 == 0) n>>=2;
        if (n % 8 == 7) return 4;
        if (isSquare(n)) return 1;
        int sqrt_n = (int) sqrt(n);
        for (int i = 1; i <= sqrt_n; i++) {
            if (isSquare(n - i * i)) return 2;
        }
        return 3;
    }
    int isSquare(int n) {
        int t = (int) sqrt(n);
        return t * t == n;
    }
    /*
     *
     *     77. Combinations
     *
     */
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp(k, 0);
        int i = 0;
        while (i >= 0) {
            tmp[i]++;
            if (tmp[i] > n) i--;
            else if (i == k - 1) res.push_back(tmp);
            else {
                i++;
                tmp[i] = tmp[i-1];
            }
        }
        return res;
    }
    vector<vector<int>> combine2(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfsCombine(res, tmp, 1, n, k);
        return res;
    }
    void dfsCombine(vector<vector<int>>& res, vector<int>& tmp, int start, int n, int k) {
        if (k == 0) {
            res.push_back(tmp);
            return;
        }
        for (int i = start; i + k <= n + 1; i++) {
            tmp.push_back(i);
            dfsCombine(res, tmp, i + 1, n, k - 1);
            tmp.pop_back();
        }
    }
    /*
     *
     *     240. Search a 2D Matrix II
     *
     */
    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix[0].size() - 1;
        while (i < matrix.size() && j > -1) {
            int t = matrix[i][j];
            if (t == target) return true;
            else if (t > target) j--;
            else i++;
        }
        return false;
    }
    /*
     *
     *     80. Remove Duplicates from Sorted Array II
     *
     */
    int removeDuplicates1(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) count++;
            else nums[i - count] = nums[i];
        }
        nums.resize(nums.size() - count);
        return nums.size();
    }
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int i = 2; i < n; i++) {
            if (nums[i] == nums[i- 2 - count]) count++;
            else nums[i - count] = nums[i];
        }
        nums.resize(nums.size() - count);
        return nums.size();
    }
    int removeKDuplicates(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for (int i = 2; i < n; i++) {
            if (nums[i] == nums[i- k - count]) count++;
            else nums[i - count] = nums[i];
        }
        nums.resize(nums.size() - count);
        return nums.size();
    }
    /*
     *
     *     109. Convert Sorted List to Binary Search Tree
     *
     */
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, NULL);
    }
    TreeNode* buildTree(ListNode* head, ListNode* tail) {
        if (head == tail) return NULL;
        if (head->next == tail) return new TreeNode(head->val);
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = buildTree(head, slow);
        root->right = buildTree(slow->next, tail);
        return root;
    }
    /*
     *
     *     86. Partition List
     *
     */
    ListNode* partition(ListNode* head, int x) {
        ListNode* greater = new ListNode(0);
        ListNode* p = greater;
        ListNode* smaller = new ListNode(0);
        ListNode* q = smaller;
        ListNode* next;
        while (head) {
            next = head->next;
            if (head->val < x) {
                q->next = head;
                q = q->next;
            } else {
                p->next = head;
                p = p->next;
            }
            head->next = NULL;
            head = next;
        }
        q->next = greater->next;
        return smaller->next;
    }
    /*
     *
     *     130. Surrounded Regions
     *
     */
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        int i, j;
        for (i = 0; i < m; i++) {
            check(board, i, 0, m, n);
            
            if (n > 1) check(board, i, n - 1, m, n);
        }
        for (j = 0; j < n; j++) {
            check(board, 0, j, m, n);
            if (m > 1) check(board, m - 1, j, m, n);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }
    void check(vector<vector<char>>& board, int i, int j, int m, int n) {
        if (board[i][j] == 'O') {
            board[i][j] = '1';
            if (i > 1) check(board, i - 1, j, m, n);
            if (j > 1) check(board, i, j - 1, m, n);
            if (i < m - 1) check(board, i + 1, j, m, n);
            if (j < n - 1) check(board, i, j + 1, m, n);
        }
    }
    /*
     *
     *     93. Restore IP Addresses
     *
     */
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        
        int length = s.length();
        if (length < 4 || length > 12) return res;
        string s1, s2, s3, s4;
        for (int first = 1; first < 4; first++) {
            s1 = s.substr(0, first);
            if (s1[0] == '0' && s1.length() > 1) continue;
            if (stol(s1) < 256) {
                for (int second = first + 1; second < length && second < first + 4; second++) {
                    s2 = s.substr(first, second - first);
                    if (s2[0] == '0' && s2.length() > 1) continue;
                    if (stol(s2) < 256) {
                        for (int third = second + 1; third < length && third < second + 4; third++) {
                            s3 = s.substr(second, third - second);
                            if (s3[0] == '0' && s3.length() > 1) continue;
                            if (stol(s3) < 256) {
                                s4 = s.substr(third);
                                if (s4[0] == '0' && s4.length() > 1) continue;
                                if (stol(s4) < 256) res.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
    /*
     *
     *     33. Search in Rotated Sorted Array
     *
     */
    int searchInRotateArray(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        int low = 0, high = n - 1;
        int mid, start;
        while (low < high) {
            mid = (low + high) / 2;
            if (nums[mid] > nums[high]) low = mid + 1;
            else high = mid;
        }
        start = low;
        low = 0; high = n - 1;
        while (low <= high) {
            mid = ((low + high) / 2 + start) % n;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
    int searchInRotateArray_method2(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        int left = 0, right = n - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            else if ((nums[left] <= nums[mid] && (nums[mid] < target || target < nums[left])) || (nums[left] > nums[mid] && nums[mid] < target && target <= nums[right])) left = mid + 1;
            // else if ((nums[mid]>nums[left] && (target>nums[mid] || (target<nums[left]))) || (nums[mid]<nums[left] && target>nums[mid] && target<=nums[right])) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    /*
     *
     *     81. Search in Rotated Sorted Array II
     *
     */
    bool searchInRotateArray_withDuplicate(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) return false;
        int left = 0, right = size - 1;
        int mid;
        while (left <= right) {
            while (nums[left] == nums[left + 1]) left++;
            while (nums[right]  == nums[right - 1]) right--;
            mid = (left + right) / 2;
            if (nums[mid] == target) return true;
            if ((nums[left] <= nums[mid] && (nums[left] > target || nums[mid] < target)) || (nums[left] > nums[mid] && (nums[mid] < target && nums[right] >= target))) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
    /*
     *
     *     319. Bulb Switcher
     *
     */
    int bulbSwitch(int n) {
        return sqrt(n);
    }
    /*
     *
     *     289. Game of Life
     *
     */
    void gameOfLife(vector<vector<int>>& board) {
        // 2 = 10 0->1
        // 3 = 11 1->1
        // 1 = 01 1->0
        // 0 = 00 0->0
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        int i, j;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                int lives = countLives(board, i, j, m, n);
                if (board[i][j] == 1) {
                    if (lives < 2 || lives > 3) board[i][j] = 1;
                    else board[i][j] = 3;
                } else if (board[i][j] == 0) {
                    if (lives == 3) board[i][j] = 2;
                }
            }
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
    int countLives(vector<vector<int>>& board, int x, int y, int m, int n) {
        // this calculation includes board[x][y], therefor count = -(board[x][y] & 1)
        int count = -(board[x][y] & 1);
        for (int i = max(x - 1, 0); i <= min(x + 1, m - 1); i++) {
            for (int j = max(y - 1, 0); j <= min(y + 1, n - 1); j++) {
                count += board[i][j] & 1;
                // 3(11, 1->1) & 1 = 1, 2(10, 0->1) & 1 = 0, 1(01, 1->0) & 1 = 1, 0(00, 0->0) & 1 = 0
            }
        }
        return count;
    }
    /*
     *
     *     306. Additive Number
     *
     */
    bool isAdditiveNumber(string num) {
        int l = num.length();
        if (l < 3) return false;
        return isSubAdditiveNumber(num, 0, l, 1, 1);
    }
    bool isSubAdditiveNumber(string num, int start, int length, int num1length, int num2length) {
        string sub3, res;
        long num1, num2, num3;
        int maxl1 = num[start] == '0' ? 1 : length - start - 2;
        for (int l1 = num1length; l1 <= maxl1; l1++) {
            for (int l2 = num2length; start + l1 + l2 <= length - 1; l2++) {
                if (num[start + l1] == '0' && l2 > 1) continue;
                num1 = stol(num.substr(start, l1));
                num2 = stol(num.substr(start + l1, l2));
                num3 = num1 + num2;
                sub3 = to_string(num3);
                res = num.substr(start + l1 + l2);
                if (res.find(sub3) == 0) {
                    if (start + l1 + l2 + sub3.length() == length) return true;
                    else if (isSubAdditiveNumber(num, start + l1, length, l2, sub3.length())) return true;
                }
            }
        }
        return false;
    }
    /*
     *
     *     347. Top K Frequent Elements
     *
     */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int n : nums) hash[n]++;
        vector<pair<int, int>> queue(hash.size());
        int i = 0;
        for (auto it = hash.begin(); it != hash.end(); it++) {
            queue[i] = make_pair(it->first, it->second);
            i++;
        }
        
//        bool sorTopKFrequent(pair<int, int> a, pair<int, int> b) {
//            return a.second < b.second;
//        }
//        sort(queue.begin(), queue.end(), sorTopKFrequent);
        vector<int> res(k);
        for (i = 0; i < k; i++) {
            res[i] = queue[i].first;
        }
        return res;
    }
    /*
     *
     *     229. Majority Element II
     *
     */
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0, a = 0, b = 1;
        for (auto n: nums) {
            if (a == n) count1++;
            else if (b == n) count2++;
            else if (count1 == 0) a = n;
            else if (count2 == 0) b = n;
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        
        for (auto n : nums) {
            if (a == n) count1++;
            else if (b == n) count2++;
        }
        vector<int> res;
        if (count1 > nums.size()/3) res.push_back(a);
        if (count2 > nums.size()/3) res.push_back(a);
        
        return res;
    }
    /*
     *
     *     241. Different Ways to Add Parentheses   QuestionEditorial Solution
     *
     */
    
    vector<int> diffWaysToCompute(string input) {
        vector<int> numbers;
        vector<char> operation;
        string num = "";
        int l = input.length();
        for (int i = 0; i < input.length(); i++) {
            char t = input[i];
            if (t <= '9' && t >= '0') {
                num += t;
            } else {
                operation.push_back(t);
                int tmp = stoi(num);
                numbers.push_back(tmp);
                num = "";
            }
        }
        if (num != "") numbers.push_back(stoi(num));
        vector<int> res =subCompute(numbers, operation, 0, numbers.size() - 1);
        return res;
    }
    vector<int> subCompute(vector<int> numbers, vector<char> operation, int start, int end) {
        vector<int> res, front, others;
        if (end - start == 1) {
            res.push_back(getComputeResult(numbers[start], numbers[end], operation[end - 1]));
            return res;
        }
        for (int i = 0; start + i < end; i++) {
            if (i == 0) {
                others = subCompute(numbers, operation, start + 1, end);
                for (int j = 0; j < others.size(); j++) {
                    int tmp =getComputeResult(numbers[start], others[j], operation[start]);
                    res.push_back(tmp);
                }
            } else if (i + start == end - 1) {
                front = subCompute(numbers, operation, start, end - 1);
                for (int j = 0; j < front.size(); j++) {
                    res.push_back(getComputeResult(front[j], numbers[end], operation[end - 1]));
                }
            } else {
                front = subCompute(numbers, operation, start, start + i);
                others = subCompute(numbers, operation, start + i + 1, end);
                for (int j = 0; j < front.size(); j++) {
                    for (int k = 0; k < others.size(); k++) {
                        res.push_back(getComputeResult(front[j], others[k], operation[start + i]));
                    }
                }
            }
        }
        return res;
    }
    int getComputeResult(int a, int b, char op) {
        if (op == '+') return a + b;
        else if (op == '-') return a - b;
        else return a * b;
    }
    /*
     *
     *     334. Increasing Triplet Subsequence
     *
     */
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int t = nums[i];
            if (t <= min1) {
                min1 = t;
            } else if (t <= min2) {
                min2 = t;
            } else {
                return true;
            }
        }
        return false;
    }
    /*
     *
     *     280. Wiggle Sort &
     *
     */
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (((i & 1) && nums[i] < nums[i - 1]) || (!(i & 1) && nums[i] > nums[i - 1])) swap(nums[i], nums[i - 1]);
        }
    }
    void wiggleSortII(vector<int>& nums) {
        int n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int median = *midptr; // find median
        int first = 0, mid = 0, last = n-1;
        while(mid <= last) {
            int actmid = map_index(mid, n);
            int actfirst = map_index(first, n);
            int actlast = map_index(last, n);
            // j: from 0 to 9;
            // map index: 1 3 5 7 9 0 2 4 6 8
            // 5 3 1 7 9 0 2 4 6 8
            // 5 1 3 7 9 0 2 4 6 8
            // 5 1 7 3 9 0 2 4 6 8
            //
            if (nums[actmid] > median) {
                swap(nums[actfirst], nums[actmid]);
                first++;
                mid++;
            } else if (nums[actmid] < median) {
                swap(nums[actlast], nums[actmid]);
                last--;
            } else {
                mid++;
            }
        }
    }
    /*
     *
     *     280. Wiggle Sort
     *
     */
    int map_index(int idx, int n) {
        // original index 0 1 2 3 4 5 6 7 8 9
        // after map      1 3 5 7 9 0 2 4 6 8
        
        return (2 * idx + 1) % (n | 1);
        // (n | 1) returns the nearest odd number larger than n;
        // here (n | 1) == 11;
    }
    /*
     *
     *     318. Maximum Product of Word Lengths
     *
     */
    
    int maxProduct(vector<string>& words) {
        int l = words.size();
        if (l < 2) return 0;
        vector<int> mask(l);
        for (int i = 0; i < l; i++) {
            mask[i] = 0;
            string s = words[i];
            for (int j = 0; j < s.length(); j++) {
                mask[i] |= 1 << (s[j] - 'a');
            }
        }
        int res = 0;
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                if ((mask[i] & mask[j]) == 0) res = max(res, int(words[i].length() * words[j].length()));
            }
        }
        return res;
    }
    /*
     *
     *     59. Spiral Matrix II
     *
     */
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) return vector<vector<int>>();
        int row_min = 0, col_min = 0, row_max = n - 1, col_max = n - 1;
        int value = 1, row = 0, col = 0;
        vector<vector<int>> res(n, vector<int>(n));
        while (value <= n*n) {
            for (col = col_min, row = row_min; col <= col_max; col++, value++) {
                res[row][col] = value;
            }
            row_min++;
            for (col = col_max, row = row_min; row <= row_max; row++, value++) {
                res[row][col] = value;
            }
            col_max--;
            for (col = col_max, row = row_max; col >= col_min; col--, value++) {
                res[row][col] = value;
            }
            row_max--;
            for (col = col_min, row = row_max; row >= row_min; row--, value++) {
                res[row][col] = value;
            }
            col_min++;
            
        }
        return res;
    }
    /*
     *
     *     386. Lexicographical Numbers
     *
     */
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur = 1;
        for (int i = 1; i <= n; i++) {
            res[i - 1] = cur;
            if (cur * 10 <= n) cur *=10;
            else if (cur % 10 != 9 && cur < n) cur++;
            else {
                while ((cur / 10) % 10 == 9) cur /= 10;
                cur = cur / 10 + 1;
            }
        }
        return res;
    }
    /*
     *
     *     322 coin change
     *
     */
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        int l = coins.size();
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < l; j++) {
                if (i >= coins[j]) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
    /*
     *
     *     222. Count Complete Tree Nodes
     *
     */
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int num = 1;
        TreeNode* curL = root->left;
        TreeNode* curR = root->left;
        while (curR) {
            curR = curR->right;
            curL = curL->left;
            num <<= 1;
        }
        return num + (curL == NULL ? countNodes(root->right):countNodes(root->left));
    }
    /*
     *
     *     140. Word Break II
     *
     */
    vector<string> wordBreak2(string s, unordered_set<string>& wordDict) {
        vector<vector<string>> res(s.length() + 1, vector<string> ());
        if (wordDict.find(s) != wordDict.end()) {
            res[s.length()].push_back(s);
            return res[s.length()];
        }
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        string sub;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j]) {
                    sub = s.substr(j, i - j);
                    if (wordDict.find(sub) != wordDict.end()) {
                        dp[i] = true;
                        if (res[j].size() == 0) res[i].push_back(sub);
                        else {
                            for (int k = 0; k < res[j].size(); k++) {
                                res[i].push_back(res[j][k] + " " + sub);
                            }
                        }
                    }
                }
            }
        }
        return res[s.length()];
    }
    /*
     *
     *     332. Reconstruct Itinerary
     *
     */
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> table;
        vector<string> route;
        for (int i = 0; i < tickets.size(); i++) {
            table[tickets[i].first].insert(tickets[i].second);
        }
        visit("JFK", table, route);
        reverse(route.begin(), route.end());
        return route;
    }
    void visit(string start, unordered_map<string, multiset<string>>& table, vector<string>& route) {
        while (table[start].size()) {
            string next = *table[start].begin();
            table[start].erase(table[start].begin());
            visit(next, table, route);
        }
        route.push_back(start);
    }
    /*
     *
     *     311. Sparse Matrix Multiplication
     *
     */
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.empty() || B.empty()) return vector<vector<int>> ();
        vector<vector<int>> result(A.size(), vector<int> (B[0].size(), 0));
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (A[i][j]) {
                    for (int k = 0; k < B[0].size(); k++) {
                        if (B[j][k]) {
                            result[i][k] += A[i][j] * B[j][k];
                        }
                    }
                }
            }
        }
        return result;
    }
    /*
     *
     *     395. Longest Substring with At Least K Repeating Characters
     *
     */
    int longestSubstring(string s, int k) {
        return helper_395(s, k, 0, s.length());
    }
    int helper_395(string s, int k, int begin, int end) {
        if (end - begin < k) return 0;
        int map[256]{};
        for (int i = begin; i < end; i++) map[s[i]]++;
        for (int i = begin; i < end; i++) {
            if (map[s[i]] < k) return max(helper_395(s, k, begin, i), helper_395(s, k, i + 1, end));
        }
        return end - begin;
        
    }
    /*
     *
     *     159. Longest Substring with At Most Two Distinct Characters
     *
     */
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int length = 0;
        int start = 0;
        int end = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) continue;
            else if (end >= 0 && s[i] != s[end]) {
                length = max(length, i - start);
                start = end + 1;
            }
            end = i - 1;
        }
        return max(length, (int)s.length() - start);
    }
    /*
     *
     *     340 Longest Substring with At Most K Distinct Characters
     *
     */
    int lengthOfLongestSubstringKDistinct(string s, int K) {
        int count[256];
        memset(count, 0, sizeof(count));
        int start = 0;
        int maxLength = 0;
        int numDistinct = 0;
        for (int i = 0; i < s.length(); i++) {
            if (count[s[i]] == 0) numDistinct++;
            count[s[i]]++;
            while (numDistinct > K) {
                count[s[start]]--;
                if (count[s[start]] == 0) numDistinct--;
                start++;
            }
            maxLength = max(i - start + 1, maxLength);
        }
        return maxLength;
    }
    /*
     *
     *    163  Missing Ranges
     *
     */
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        long pre = lower - 1;
        long cur;
        for (int i = 0; i <= nums.size(); i++) {
            cur = i != nums.size()? nums[i]:upper + 1;
            if (cur - pre >= 2) {
                result.push_back(getRange(pre + 1, cur - 1));
            }
            pre = cur;
        }
        return result;
    }
    string getRange(int start, int end) {
        return start == end? to_string(start):to_string(start) + "->" + to_string(end);
        
    }
    /*
     *
     *     161. One Edit Distance
     *
     */
    bool isOneEditDistance(string s, string t) {
        if (s == t) return true;
        int ldif = s.length() - t.length();
        if (abs(ldif) > 1) return false;
        if (t == "" || s == "") return true;
        if (ldif == -1) return isOneEditDistance(t, s);
        int i = 0, j = 0;
        while(s[i] == t[j] && i < s.length() && j < t.length()) {
            i++;
            j++;
        }
        if (ldif == 1) {
            if (i == s.length() - 1) return true;
            else {
                i++;
                while(s[i] == t[j] && i < s.length() && j < t.length()) {
                    i++;
                    j++;
                }
                if (i == s.length()) return true;
            }
        } else {
            if (i == s.length()) return true;
            else {
                i++;j++;
                while(s[i] == t[j] && i < s.length() && j < t.length()) {
                    i++;
                    j++;
                }
                if (i == s.length()) return true;
            }
        }
        return false;
    }
    bool isOneEditDistance2(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n) return isOneEditDistance(t, s);
        if (m - n > 1) return false;
        int i = 0, shift = m - n;
        while (i < n && s[i] == t[i]) i++;
        if (i == m) return shift > 0;
        if (shift == 0) i++;
        while (i < m && s[i + shift] == t[i]) i++;
        return i == m;
    }
    /*
     *
     *     343. Integer Break
     *
     */
    int integerBreak(int n) {
        if (n == 2) return 1;
        else if (n == 3) return 2;
        else if (n % 3 == 0) return pow(3, n /3);
        else if (n % 3 == 1) return 4 * pow(3, (n - 4) / 3);
        else return 2 * pow(3, (n - 2) / 3);
    }
    /*
     *
     *     309. Best Time to Buy and Sell Stock with Cooldown
     *
     */
    int maxProfit_withCooldown(vector<int> & prices) {
        int days = prices.size();
        if (days < 2) return 0;
        int result = 0;
        vector<int> sell(days, 0);
        vector<int> buy(days, 0);
        buy[0] = -prices[0];
        buy[1] = -prices[1];
        for (int i = 1; i < days; i++) {
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1] - prices[i - 1] + prices[i]);
            if (result < sell[i]) result = sell[i];
            if (i != 1) buy[i] = max(sell[i-2] - prices[i], buy[i - 1] + prices[i-1] - prices[i]);
        }
        return result;
        
    }
    /*
     *
     *     199. Binary Tree Right Side View
     *
     */
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        queue<TreeNode*> level;
        level.push(root);
        queue<TreeNode*> next;
        while(!level.empty() || !next.empty()) {
            TreeNode* t = level.front();
            level.pop();
            if (t->left) next.push(t->left);
            if (t->right) next.push(t->right);
            if (level.empty()) {
                result.push_back(t->val);
                swap(level, next);
            }
        }
        return result;
    }
    /*
     *
     *     331. Verify Preorder Serialization of a Binary Tree
     *
     */
    vector<string> splitString(string s, char seperator) {
        vector<string> elems;
        stringstream ss;
        ss.str(s);
        string item;
        while (getline(ss, item, seperator)) {
            elems.push_back(item);
        }
        return elems;
    }
    bool isValidSerialization(string preorder) {
        vector<string> nodes = splitString(preorder, ',');
        int dif = 1;
        for (int i = 0; i < nodes.size(); i++) {
            dif--;
            if (dif < 0) return false;
            else if (nodes[i] != "#") dif += 2;
        }
        return dif == 0;
    }
    /*
     *
     *     167. Two Sum II - Input array is sorted
     *
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2);
        if (numbers.size() < 2) return res;
        int left = 0, right = numbers.size() - 1, sum;
        while (left < right) {
            sum = numbers[left] + numbers[right];
            if (sum == target) {
                res[0] = left + 1;
                res[1] = right + 1;
                break;
            } else if (sum > target) right--;
            else left++;
        }
        return res;
    }
    /*
     *
     *     337. House Robber III
     *
     */
    int rob(TreeNode* root) {
        int l, r;
        return tryRob(root, l, r);
    }
    int tryRob(TreeNode* root, int& leftTotal, int& rightTotal) {
        if (!root) return 0;
        int leftLeftTotal = 0, leftRightTotal = 0;
        int rightLeftTotal = 0, rightRightTotal = 0;
        leftTotal = tryRob(root->left, leftLeftTotal, leftRightTotal);
        rightTotal = tryRob(root->right, rightLeftTotal, rightRightTotal);
        return max(root->val + leftLeftTotal + leftRightTotal + rightLeftTotal + rightRightTotal, leftTotal + rightTotal);
    }
    /*
     *
     *     378. Kth Smallest Element in a Sorted Matrix
     *
     */
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            int count = 0;
            for (int i = 0; i < n; i++) {
                auto row = matrix[i];
                count += upper_bound(row.begin(), row.end(), mid) - row.begin();
            }
            if (count < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    /*
     *
     *     221. Maximal Square
     *
     */
    int maximalSquare1(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        int maxLength = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    int length = checkSquare(matrix, i, j, m, n);
                    maxLength = max(length, maxLength);
                    cout<<length<<endl;
                    j += length - 1;
                    i += length - 1;
                };
            }
        }
        return maxLength * maxLength;
    }
    int checkSquare(vector<vector<char>>& matrix, int x, int y, int m, int n) {
        int length;
        for (length = 1; length + x <= m && length + y <= n; length++) {
            for (int i = x; i < x + length; i++) {
                for (int j = y; j < y + length; j++) {
                    cout<<"matrix[i][j]: "<<matrix[i][j]<<endl;
                    cout<<"length: "<<length<<endl;
                    if (matrix[i][j] == 0) break;
                }
            }
        }
        return length;
    }
    //time: O(mn) Space:O(mn);
    int maximalSquare2(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        int maxLength = 0;
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] - '0';
            if (dp[i][0] == 1) maxLength = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j] - '0';
            if (dp[0][j] == 1) maxLength = 1;
        }
        for (int i = 1; i < m; i++) {
            
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                    maxLength = max(dp[i][j], maxLength);
                } else {
                    dp[i][j] = matrix[i][j] - '0';
                }
            }
        }
        return maxLength * maxLength;
    }
    //time: O(mn) Space:O(n);
    int maximalSquare3(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        int maxLength = 0, prev = matrix[0][0];
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int tmp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min(prev, min(dp[j-1], tmp)) + 1;
                    maxLength = max(dp[j], maxLength);
                } else {
                    dp[j] = 0;
                }
                prev = tmp;
            }
        }
        return maxLength * maxLength;
    }
    /*
     *
     *     277. Find the Celebrity
     *
     */
    int knows(int a, int b) {return true;}
    int findCelebrity(int n) {
        if (n <= 1) return n;
        int candidate = 0;
        for (int i = 1; i < n; i++) {
            if (!knows(i, candidate)) candidate = i;
        }
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;
            if (!knows(i, candidate) || knows(candidate, i)) return -1;
        }
        return candidate;
    }
    /*
     *
     *     406. Queue Reconstruction by Height
     *
     */
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [] (pair<int, int> a, pair<int, int> b) {return a.first > b.first || (a.first == b.first && a.second < b.second); });
        vector<pair<int, int>> result;
        for (auto p : people) {
            result.insert(result.begin() + p.second, p);
        }
        return result;
    }
    /*
     *
     *     253. Meeting Rooms II
     *
     */
    int minMeetingRooms(vector<Interval>& intervals) {
        int size = intervals.size();
        vector<int> start(size, 0);
        vector<int> end(size, 0);
        
        for (int i = 0; i < size; i++) {
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int room = 0;
        for (int i = 0, j = 0; i < size; i++) {
            if (start[i] < end[j]) room++;
            else j++;
        }
        return room;
    }
    /*
     *
     *     250. Count Univalue Subtrees
     *
     */
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        helper250(root, count);
        return count;
    }
    bool helper250(TreeNode* root, int& count) {
        if (root == NULL) return true;
        if (!root->left && !root->right) {
            count++;
            return true;
        }
        bool left = helper250(root->left, count);
        bool right = helper250(root->right, count);
        if (left && right && (root->left == NULL || root->left->val == root->val) && (root->right == NULL || root->right->val == root->val)) {
            count++;
            return true;
        }
        return false;
    }
    /*
     *
     *     300. Longest Increasing Subsequence
     *
     */
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> result;
        int length = 1;
        for (int i = 0; i < nums.size(); i++) {
            auto it = lower_bound(result.begin(), result.end(), nums[i]);
            cout<<result[it-result.begin()]<<endl;
            if (it == result.end()) result.push_back(nums[i]);
            else *it = nums[i];
        }
        return result.size();
    }
    /*
     *
     *     357. Count Numbers with Unique Digits
     *
     */
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n > 10) return countNumbersWithUniqueDigits(10);
        int total = 9;
        for (int i = 1; i < n && i <= 9; i++) {
            total *= (10 - i);
        }
        return total + countNumbersWithUniqueDigits(n - 1);
    }
    /*
     *
     *     95. Unique Binary Search Trees II
     *
     */
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateSubTrees(1, n);
    }
    vector<TreeNode*> generateSubTrees(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(NULL);
            return res;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = generateSubTrees(start, i - 1);
            vector<TreeNode*> right = generateSubTrees(i + 1, end);
            
            for (int l = 0; l < left.size(); l++) {
                for (int r = 0; r < right.size(); r++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[l];
                    root->right = right[r];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    /*
     *
     *     209. Minimum Size Subarray Sum
     *
     */
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, sum = 0, length = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >=  s) {
                length = min(length, i - start + 1);
                sum -= nums[start];
                start++;
            }
        }
        return length == INT_MAX?0:length;
    }
    /*
     *
     *     207. Course Schedule
     *
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<set<int>> graph = makeGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false);
        vector<bool> color(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (color[i] == false && dfsHasCircle(i, visited, graph, color)) return false;
        }
        return true;
    }
    vector<set<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<set<int>> graph(numCourses);
        for (auto it = prerequisites.begin(); it != prerequisites.end(); it++) {
            graph[it->first].insert(it->second);
        }
        return graph;
    }
    bool dfsHasCircle(int node, vector<bool>& visited, vector<set<int>>& graph, vector<bool>& color) {
        visited[node] = true;
        color[node] = true;
        for (int neighbor : graph[node]) {
            if (visited[neighbor] || dfsHasCircle(neighbor, visited, graph, color)) return true;
        }
        visited[node] = false;
        return false;
    }
    /*
     *
     *     274. H-Index
     *
     */
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        sort(citations.begin(), citations.end(), [](int a, int b) {return a < b;});
        int len = citations.size();
        for (int i = 0; i < citations.size(); i++) {
            if (len <= citations[i]) return len;
            else {
                len--;
            }
        }
        return len;
    }
    /*
     *
     *     216. Combination Sum III
     *
     */
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if (n > 45 || k > 9) return result;
        vector<int> path;
        dfs(k, n, result, path);
        return result;
    }
    void dfs(int k, int n, vector<vector<int>>& result, vector<int>& path) {
        if (n == 0 && k == 0) {
            result.push_back(path);
        } else if (k > 0) {
            for (int i = path.empty() ? 1: path.back() + 1; i <= 9; i++) {
                if (n >= i) {
                    path.push_back(i);
                    dfs(k - 1, n - i, result, path);
                    path.pop_back();
                }
            }
        }
    }
    /*
     *
     *     60. Permutation Sequence
     *
     */
    string getPermutation(int n, int k) {
        string res;
        string nums = "123456789";
        int fact[n];
        fact[0] = 1;
        for (int i = 1; i < n; i++) fact[i] = i * fact[i - 1];
        k--;
        for (int i = n; i > 0; i--) {
            int j = k / fact[i - 1];
            k %= fact[i - 1];
            res += nums[j];
            cout<<res<<endl;
            nums.erase(nums.begin() + j);
        }
        return res;
    }
    /*
     *
     *     156. Binary Tree Upside Down
     *
     */
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == NULL) return root;
        stack<TreeNode*> S;
        while (root->left) {
            S.push(root);
            root = root->left;
        }
        if (S.empty()) {
            root->right = NULL;
            return root;
        }
        TreeNode* newRoot = root;
        while (!S.empty()) {
            TreeNode* node = S.top();
            S.pop();
            root->left = node->right;
            node->left = NULL;
            node->right = NULL;
            root->right = node;
            root = root->right;
        }
        return newRoot;
    }
    /*
     *
     *    375. Guess Number Higher or Lower II
     *
     */
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for (int i = 2; i <= n; i++) {
            for (int j = i-1; j >= 1; j--) {
                if (j+1 == i) dp[j][i] = j;
                else {
                    int tempMin = INT_MAX;
                    for (int k = j+1; k < i; k++) {
                        tempMin = min(max(dp[j][k-1], dp[k+1][i]) + k, tempMin);
                    }
                    dp[j][i] = tempMin;
                }
            }
        }
        return dp[1][n];
    }
    /*
     *
     *    377. Combination Sum IV
     *
     */
    int combinationSum4(vector<int>& nums, int target) {            //TLE
        if (target == 0) return {};
        vector<vector<int>> result;
        vector<int> path;
        dfs_377(nums, target, path, result);
        return result.size();
    }
    void dfs_377(vector<int>& nums, int target, vector<int>& path, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int rest = target - num;
            if (rest < 0) break;
            path.push_back(num);
            dfs_377(nums, rest, path, result);
            path.pop_back();
        }
    }
    int combinationSum4_method2(vector<int>& nums, int target) {    //accepted
        vector<int> dp(target+1, 0);
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (num > i) break;
                else if (num == i) dp[i] += 1;
                else {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
    /*
     *
     *    390. Elimination Game
     *
     */
    int lastRemaining(int n) {
        return n == 1? 1 : (n/2 + 1 - lastRemaining(n/2)) * 2;
    }
    /*
     *
     *    256. Paint House
     *
     */
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        n--;
        int pre;
        for (int i = 1, pre = 0; i <= n; i++) {
            pre = i - 1;
            costs[i][0] += min(costs[pre][1], costs[pre][2]);
            costs[i][1] += min(costs[pre][0], costs[pre][2]);
            costs[i][2] += min(costs[pre][1], costs[pre][0]);
        }
        return min(min(costs[n][0], costs[n][1]), costs[n][2]);
    }
    /*
     *
     *    285. Inorder Successor in BST
     *
     */
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> S;
        bool isNode = false;
        while (root) {
            S.push(root);
            root = root->left;
        }
        while (!S.empty()) {
            TreeNode* node = S.top();
            if (isNode) return node;
            S.pop();
            if (node == p) isNode = true;
            if (node->right) {
                node = node->right;
                while (node) {
                    S.push(node);
                    node = node->left;
                }
            }
        }
        return NULL;
    }
    // since it's a binary search tree instead of just binary tree, there is another smiple method;
    TreeNode* inorderSuccessor_method2(TreeNode* root, TreeNode* p) {
        if (root == NULL || p == NULL) return NULL;
        TreeNode* suc = NULL;
        while (root) {
            if (root->val <= p->val) {
                root = root->right;
            } else {
                suc = root;
                root = root->left;
            }
        }
        return suc;
    }
    /*
     *
     *    82. Remove Duplicates from Sorted List II
     *
     */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode* pre = fakeHead;
        ListNode* p = head;
        ListNode* pnext;
        while (p) {
            pnext = p->next;
            int val = p->val;
            if (pnext && pnext->val == val) {
                while (pnext && pnext->val == val) pnext = pnext->next;
                pre->next = pnext;
                p = pnext;
            } else {
                pre = p;
            }
            p = pnext;
        }
        return fakeHead->next;
    }
    /*
     *
     *    320. Generalized Abbreviation
     *
     */
    vector<string> generateAbbreviations(string word) {
        int l = word.length();
        vector<string> res;
        helper(word, res, "", 0, false);
        return res;
    }
    void helper(string word, vector<string>& res, string abbr, int start, bool isPreNum) {
        if (start == word.length()) {
            res.push_back(abbr);
            return;
        }
        helper(word, res, abbr + word[start], start + 1, false);
        if (!isPreNum) {
            for (int i = 1; start + i <= word.length(); i++) {
                helper(word, res, abbr + to_string(i), start + i, true);
            }
        }
    }
    /*
     *
     *    113. Path Sum II -- negative may exist
     *
     */
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs_113(root, sum, res, path);
        return res;
    }
    void dfs_113(TreeNode* node, int sum, vector<vector<int>>& res, vector<int>& path) {
        if (node == NULL) return;
        sum -= node->val;
        path.push_back(node->val);
        if (node->left) dfs_113(node->left, sum, res, path);
        if (node->right) dfs_113(node->right, sum, res, path);
        if (!node->left && !node->right && sum == 0) res.push_back(path);
        path.pop_back();
    }
    /*
     *
     *    394. Decode String
     *
     */
    string decodeString(string s) {
        int index = 0;
        return recursiveDecode(s, index);
    }
    string recursiveDecode(string s, int& index) {
        int num = 0;
        string res = "";
        while (index < s.length() && s[index] != ']') {
            if (isalpha(s[index])) {
                res += s[index];
                index++;
            } else {
                while (isdigit(s[index])) {
                    num = num * 10 + s[index] - '0';
                    index++;
                }
                index++;
                string temp = recursiveDecode(s, index);
                index++;
                while (num != 0) {
                    res += temp;
                    num--;
                }
            }
        }
        return res;
    }
    /*
     *
     *    298. Binary Tree Longest Consecutive Sequence
     *
     */
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) return 0;
        return max(helper_298(root->left, 1, root->val), helper_298(root->right, 1, root->val));
    }
    int helper_298(TreeNode* node, int count, int val) {
        if (node == NULL) return count;
        if (node->val == val + 1) count++;
        else count = 1;
        return max(max(helper_298(node->left, count, node->val),helper_298(node->right, count, node->val)), count);
    }
};
