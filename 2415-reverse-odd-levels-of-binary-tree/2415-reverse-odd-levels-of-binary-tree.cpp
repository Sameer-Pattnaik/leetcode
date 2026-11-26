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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
    
        int cnt=0;

        while(!q.empty()){
            vector<TreeNode*>v;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
                v.push_back(temp);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            
            if(cnt%2==1){
                int left=0;
                int right=v.size()-1;
                while(left<right){
                    int temp=v[left]->val;
                    v[left]->val=v[right]->val;
                    v[right]->val=temp;
                    left++;
                    right--;
                }
            }
            cnt++;
        }
        return root;
    }
};