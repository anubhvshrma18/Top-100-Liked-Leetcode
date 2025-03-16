/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
    public:
        TreeNode* sorted(vector<int> &nums,int s,int e){
            if(s>e)
                return NULL;
            int m=(s+e)/2;
            TreeNode* node=new TreeNode(nums[m]);
            node->left=sorted(nums,s,m-1);
            node->right=sorted(nums,m+1,e);
            return node;
        }
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return sorted(nums,0,nums.size()-1);
        }
    };