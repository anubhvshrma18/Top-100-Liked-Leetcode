#include <string>
#include <stack>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> stack;
        int maxLength = 0;
        int lastInvalid = -1;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                if (stack.empty()) {
                    lastInvalid = i;
                } else {
                    stack.pop();
                    if (stack.empty()) {
                        maxLength = std::max(maxLength, i - lastInvalid);
                    } else {
                        maxLength = std::max(maxLength, i - stack.top());
                    }
                }
            }
        }

        return maxLength;
    }
};