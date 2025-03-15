/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        // Flatten the left and right subtrees
        flatten(root->left);
        flatten(root->right);

        // Store the right subtree
        TreeNode* tempRight = root->right;

        // Move the left subtree to the right
        root->right = root->left;
        root->left = nullptr;

        // Find the end of the new right subtree and attach the old right subtree
        TreeNode* current = root;
        while (current->right) {
            current = current->right;
        }
        current->right = tempRight;
    }
};