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
    int maxLevelSum(TreeNode* root) {
        vector<int>ans;
        vector<int>result;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode*temp=q.front();
            q.pop();
            if(temp==NULL)
            {
                int sum=0;
                for(int i=0;i<ans.size();i++)
                {
                    sum+=ans[i];
                }
                result.push_back(sum);
                while(ans.size()!=0)
                {
                    ans.pop_back();
                }
                if(!q.empty())
                {
                    q.push(NULL);
                    
                }
            }
            else{
                ans.push_back(temp->val);
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
        int maxNo=INT_MIN;
        int index=0;
        for(int i=0;i<result.size();i++)
        {
            maxNo=max(maxNo,result[i]);
        }
        for(int i=0;i<result.size();i++)
        {
            if(maxNo==result[i])
            {
                return i+1;
            }
        }
        return -1;
    }
};