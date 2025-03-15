#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> indices;
        int maxArea = 0;
        heights.push_back(0); // Add a sentinel value to pop all remaining bars

        for (int i = 0; i < heights.size(); ++i) {
            while (!indices.empty() && heights[i] < heights[indices.top()]) {
                int height = heights[indices.top()];
                indices.pop();
                int width = indices.empty() ? i : i - indices.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            indices.push(i);
        }

        return maxArea;
    }
};