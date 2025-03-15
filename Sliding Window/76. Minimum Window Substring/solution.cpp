#include <string>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> charCountT;
        for (char c : t) {
            charCountT[c]++;
        }

        unordered_map<char, int> charCountS;
        int left = 0, right = 0;
        int required = charCountT.size();
        int formed = 0;
        int minLength = INT_MAX;
        int minLeft = 0;

        while (right < s.size()) {
            char c = s[right];
            charCountS[c]++;

            if (charCountT.count(c) && charCountS[c] == charCountT[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                c = s[left];

                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minLeft = left;
                }

                charCountS[c]--;
                if (charCountT.count(c) && charCountS[c] < charCountT[c]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return minLength == INT_MAX ? "" : s.substr(minLeft, minLength);
    }
};