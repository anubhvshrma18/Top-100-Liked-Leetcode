class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (i > maxReach) {
                return false; // If we can't reach this index
            }
            maxReach = max(maxReach, i + nums[i]); // Update the maximum reach
            if (maxReach >= n - 1) {
                return true; // If we can reach the last index
            }
        }
        return false; // If we finish the loop and can't reach the last index
    }
};