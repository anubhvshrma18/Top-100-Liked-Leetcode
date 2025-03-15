class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        maxPathSumHelper(root, max_sum);
        return max_sum;
    }

private:
    int maxPathSumHelper(TreeNode* node, int& max_sum) {
        if (!node) return 0;

        int left = max(0, maxPathSumHelper(node->left, max_sum));
        int right = max(0, maxPathSumHelper(node->right, max_sum));

        max_sum = max(max_sum, left + right + node->val);

        return max(left, right) + node->val;
    }
};