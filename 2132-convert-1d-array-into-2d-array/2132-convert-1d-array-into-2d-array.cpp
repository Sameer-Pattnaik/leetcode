class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
       int flattenIndex=0;
       
        vector<vector<int>>result(m,vector<int>(n));
        if(m*n!=original.size()){
            return {};
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                result[i][j]=original[flattenIndex];
                flattenIndex++;
            }
        }
        return result; 
    }
};