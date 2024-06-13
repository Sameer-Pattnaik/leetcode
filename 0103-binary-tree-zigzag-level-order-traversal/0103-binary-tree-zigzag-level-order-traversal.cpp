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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>output;
        if(root==NULL)
        {
            return output;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty())
        {
            int size=q.size();
            vector<int>ans(size);
            int index=0;
            for(int i=0;i<size;i++)
            {
                TreeNode*temp=q.front();
                q.pop();
                if(leftToRight)
                {
                    index=i;
                }
                else
                {
                    index=size-1-i;
                }
                ans[index]=temp->val;
                if(temp!=NULL)
                {
               if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
                }
            }
            output.push_back(ans);
        
            
           leftToRight=!leftToRight; 
           
        
        }
        return output;
    }
};