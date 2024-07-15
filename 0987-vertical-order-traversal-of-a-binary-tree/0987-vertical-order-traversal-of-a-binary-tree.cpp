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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
       map<int,map<int,multiset<int>>>verticalNode;
       queue<pair<TreeNode*,pair<int,int>>>q;
       q.push(make_pair(root,make_pair(0,0))); 
       while(!q.empty())
       {
        auto p=q.front();
        q.pop();
        TreeNode*frontNode=p.first;
        int hd=p.second.first;
        int lvl=p.second.second;
        verticalNode[hd][lvl].insert(frontNode->val);
        if(frontNode->left)
        {
            q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
        }
        if(frontNode->right)
        {
            q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
        }
       }
       for(auto i:verticalNode)
       {
        vector<int>col;
        for(auto j:i.second)
        {
            col.insert(col.end(),j.second.begin(),j.second.end());
        }
        ans.push_back(col);
       }
       return ans;
    }
};