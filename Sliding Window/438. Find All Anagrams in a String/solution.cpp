#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int sLen = s.size(), pLen = p.size();
        if (sLen < pLen) return result;

        unordered_map<char, int> pCount, sCount;
        for (char c : p) pCount[c]++;
        
        for (int i = 0; i < pLen; i++) sCount[s[i]]++;

        if (pCount == sCount) result.push_back(0);

        for (int i = pLen; i < sLen; i++) {
            sCount[s[i]]++;
            sCount[s[i - pLen]]--;

            if (sCount[s[i - pLen]] == 0) {
                sCount.erase(s[i - pLen]);
            }

            if (pCount == sCount) {
                result.push_back(i - pLen + 1);
            }
        }

        return result;
    }
};