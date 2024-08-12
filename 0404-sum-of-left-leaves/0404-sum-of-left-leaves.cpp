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
void traverseLeaf(TreeNode*root,int &sum,bool is_left)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->left==NULL && root->right==NULL && is_left)
    {
        sum+=root->val;
        return;
    }
    traverseLeaf(root->left,sum,true);
    traverseLeaf(root->right,sum,false);
}

      int sumOfLeftLeaves(TreeNode* root) {
      vector<int>ans;
      int sum=0;
      traverseLeaf(root,sum,false);
      return sum;
    }
};