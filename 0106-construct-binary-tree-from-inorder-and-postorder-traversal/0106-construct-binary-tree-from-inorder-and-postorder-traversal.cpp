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
int position(vector<int>&inorder,int element,int size)
{
    for(int i=0;i<size;i++)
    {
        if(inorder[i]==element)
        {
            return i;
        }
    }
    return -1;
}
TreeNode* solve(vector<int>&inorder,vector<int>&postorder,int &index,int inorderStart,int inorderEnd,int size)
{
    if(index<0 || inorderStart>inorderEnd)
    {
        return NULL;
    }
    int element=postorder[index];
    index--;
    TreeNode* root=new TreeNode(element);
    int pos=position(inorder,element,size);
    root->right=solve(inorder,postorder,index,pos+1,inorderEnd,size);
    root->left=solve(inorder,postorder,index,inorderStart,pos-1,size); 
    return root;

}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      
       int n=postorder.size();
       int postIndex=n-1;
       TreeNode*ans=solve(inorder,postorder,postIndex,0,n-1,n);
       return ans;
    }
};