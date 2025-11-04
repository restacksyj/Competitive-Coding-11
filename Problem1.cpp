// Problem Name: Reverse Polish Notation
// Time Complexity : O(n)
// Space Complexity : O(n)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// Your code here along with comments explaining your approach
// 1. We maintain a stack here to track the operations
// 2. If we see a operator, we pop two times from the stack and perform the
// operation
// 3. In the end, we return st.top()

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<string> st;
    unordered_set<string> se = {"*", "+", "-", "/"};
    for (string token : tokens) {
      if (se.count(token) > 0) {
        int first = stoi(st.top());
        st.pop();
        int second = stoi(st.top());
        st.pop();
        int val = second;
        if (token == "+") {
          val += first;
        } else if (token == "-") {
          val -= first;
        } else if (token == "*") {
          val *= first;
        } else {
          val /= first;
        }
        st.push(to_string(val));
      } else {
        st.push(token);
      }
    }

    return stoi(st.top());
  }
};
