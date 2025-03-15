class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(), root->val);
        int index = distance(inorder.begin(), it);

        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + index);
        vector<int> rightPre(preorder.begin() + 1 + index, preorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin() + index);
        vector<int> rightIn(inorder.begin() + index + 1, inorder.end());

        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);

        return root;
    }
};