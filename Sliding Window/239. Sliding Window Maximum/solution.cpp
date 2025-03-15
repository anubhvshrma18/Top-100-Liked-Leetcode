#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            // Remove elements not in the sliding window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove elements smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Start adding results to the output after the first k elements
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};