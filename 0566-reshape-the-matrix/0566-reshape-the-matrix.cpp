class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if((mat.size()*mat[0].size()!=r*c)||(mat.size()==r && mat[0].size()==c))
        {
            return mat;
        }
        int x=0;
        int y=0;
        vector<vector<int>>ans(r,vector<int>(c));
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                ans[x][y++]=mat[i][j];
                if(y==c)
                {
                    y=0;
                    x++;
                }
            }
        }
        return ans;
    }
};