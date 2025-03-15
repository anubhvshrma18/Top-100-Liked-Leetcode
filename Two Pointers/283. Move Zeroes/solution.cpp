#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0; // Pointer for the last non-zero element found
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt] = nums[i];
                lastNonZeroFoundAt++;
            }
        }
        // Fill the remaining positions with zeros
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};