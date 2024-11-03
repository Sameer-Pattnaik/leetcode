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
    int countNodes(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    bool solve(TreeNode*root,int index,int count)
    {
        if(root==NULL)
        {
            return true;
        }
        if(index>=count)
        {
            return false;
        }
        return solve(root->left,2*index+1,count) && solve(root->right,2*index+2,count);
    }
    bool isCompleteTree(TreeNode* root) {
        int count=countNodes(root);
        int index=0;
        if(solve(root,index,count))
        {
            return true;
        }
        return false;
    }
};