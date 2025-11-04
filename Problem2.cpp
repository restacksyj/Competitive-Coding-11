// Problem Name: Remove k digits
// Time Complexity : O(n)
// Space Complexity : O(n)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// Your code here along with comments explaining your approach
// 1. We maintain a stack here and if we a top value greater than current char,
// we pop it since we need to form the smallest integer
// 2. We will keep removing from stack until k is zero
// 3. the stack contains the ans in reverse order, we pop from the stack and
// remove trailing zeroes and finally return the ans

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {
    stack<char> s;

    for (int i = 0; i < num.size(); i++) {
      int x = num[i] - '0';
      while (!s.empty() && k > 0 && s.top() - '0' > x) {
        s.pop();
        k--;
      }
      s.push(num[i]);
    }

    while (k > 0 && !s.empty()) {
      s.pop();
      k--;
    }

    string ans = "";

    while (!s.empty()) {
      ans += s.top();
      s.pop();
    }

    reverse(begin(ans), end(ans));

    // removing leading zeroes
    int i = 0;
    while (ans[i] == '0') {
      i++;
    }

    ans.erase(0, i);

    if (ans.empty()) {
      return "0";
    } else {
      return ans;
    }
  }
};
