#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            if (charIndexMap.find(s[i]) != charIndexMap.end()) {
                start = max(start, charIndexMap[s[i]] + 1);
            }
            charIndexMap[s[i]] = i;
            maxLength = max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};