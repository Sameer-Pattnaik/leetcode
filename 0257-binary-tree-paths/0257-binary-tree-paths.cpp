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
    vector<string>solve(TreeNode*root,vector<string>&ans,string temp){
        temp+=to_string(root->val);
        if(root->left){
            solve(root->left,ans,temp+"->");
        }
        if(root->right){
            solve(root->right,ans,temp+"->");
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(temp);
        }
        return ans;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root){
        solve(root,ans,"");
        }
        return ans;
    }
};