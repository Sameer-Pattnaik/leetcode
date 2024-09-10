class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>>matrix;
        for(int i=0;i<image.size();i++)
        {
            vector<int>ans;
            for(int j=0;j<image[0].size();j++)
            {
               ans.push_back(image[i][j]);
            }
            reverse(ans.begin(),ans.end());
            matrix.push_back(ans);
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][j]=1;
                }
                else{
                    matrix[i][j]=0;
                }
            }
        }
        return matrix;
    }
};