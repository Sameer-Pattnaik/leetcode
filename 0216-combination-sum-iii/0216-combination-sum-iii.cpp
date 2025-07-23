class Solution {
public:
    void fun(vector<vector<int>>&mat,vector<int>&arr,int k,int n,int ind){
        if(n==0 && arr.size()==k) {
            mat.push_back(arr);
            return;
        }
        if(n==0 || ind==0) return;

        if(n>=ind){
            arr.push_back(ind);
            fun(mat,arr,k,n-ind,ind-1);
            arr.pop_back();
        }
        fun(mat,arr,k,n,ind-1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>mat;
        vector<int>arr;
        fun(mat,arr,k,n,9);
        return mat;
    }
};