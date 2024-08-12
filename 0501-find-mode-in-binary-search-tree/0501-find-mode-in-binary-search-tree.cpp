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
    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> findMode(TreeNode* root) {
       vector<int>ans;
       inorder(root,ans);
    
        map<int,int>mp;
        for(int i=0;i<ans.size();i++)
        {
            mp[ans[i]]++;
        }
        vector<int>result;
        int maxSum=0;
        for(auto it:mp)
        {
            if(it.second>maxSum)
            {
                maxSum=it.second;
            }
        }
        for(auto it:mp)
        {
            if(it.second==maxSum)
            {
                result.push_back(it.first);
            }
        }
        return result;
       
    }
};