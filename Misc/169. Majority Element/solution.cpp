#include <vector>
#include <unordered_map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> countMap;
        int n = nums.size();
        
        for (int num : nums) {
            countMap[num]++;
            if (countMap[num] > n / 2) {
                return num;
            }
        }
        
        return -1; // This line should never be reached as per problem constraints
    }
};