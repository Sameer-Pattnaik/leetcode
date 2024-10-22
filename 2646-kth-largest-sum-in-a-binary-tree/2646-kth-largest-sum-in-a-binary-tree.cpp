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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>ans;
        vector<long long>output;
       queue<TreeNode*>q;
       q.push(root);
       q.push(NULL); 
    
       while(!q.empty())
       {
        TreeNode*temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            long long sum=0;
            for(int i=0;i<output.size();i++)
            {
                sum+=output[i];
            }
            ans.push_back(sum);
            if(!q.empty())
            {
                q.push(NULL);
            }
            while(output.size()!=0)
            {
                output.pop_back();
            }
        }
        else
        {
            output.push_back(temp->val);
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
       sort(ans.begin(),ans.end(),greater<>());
       for(int i=0;i<ans.size();i++)
       {
        if(i==k-1)
        {
            return ans[i];
        }
       }
       return -1;
    }
};