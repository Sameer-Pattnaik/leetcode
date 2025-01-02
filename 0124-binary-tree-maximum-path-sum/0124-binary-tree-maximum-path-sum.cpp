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
   int max_profit=INT_MIN;
    int height(TreeNode* root){
        if (!root)return 0;
        int left_half=max(0,height(root->left));
        int right_half=max(0,height(root->right));

        max_profit=max(max_profit, left_half + right_half + root->val);
        return root->val + max(left_half,right_half);
    }
    int maxPathSum(TreeNode* root) {
        height(root);
        return max_profit;
    }
};