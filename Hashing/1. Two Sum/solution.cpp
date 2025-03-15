#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map; // To store the number and its index
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i]; // Calculate the complement
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i}; // Return the indices if found
            }
            num_map[nums[i]] = i; // Store the index of the current number
        }
        return {}; // Return an empty vector if no solution is found
    }
};