/* LC 20
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for(int i = 0; i < n; i++) {
            switch(s[i]) {
                case '(':
                case '[':
                case '{': st.push(s[i]); break;
                case ')' :if(st.empty() || st.top() != '(') return false; st.pop();break;
                case ']' :if(st.empty() || st.top() != '[') return false; st.pop();break;
                case '}' :if(st.empty() || st.top() != '{') return false; st.pop();break;
            }
        }
        return st.empty();
}

/* Tested.
 * Time complexity: O(n) where n is the length of the string.
 * Space complexity: O(n)
 */
