int dp[50][50];// dp[i][j]=min weight for convex v[i..j]
class Solution {
public:
    static int f(int i, int j, vector<int>& v){
        if (dp[i][j]!=-1) return dp[i][j];
        if (j-i<=1) return dp[i][j]=0; // only 2 sides
        if (j-i==2) return dp[i][j]=v[i]*v[i+1]*v[i+2];
        // consider the edge v[i], v[j]
        const int e=v[i]*v[j];
        int ans=INT_MAX;
        for(int k=i+1; k<j; k++)
            ans=min(ans, e*v[k]+f(i, k, v)+f(k, j, v));
        return dp[i][j]=ans;
    }
    static int minScoreTriangulation(vector<int>& v) {
        const int n=v.size();
        if (n==3) return v[0]*v[1]*v[2];
        for(int i=0; i<n; i++)
            memset(dp[i], -1, 4*n);
        return f(0, n-1, v);
    }
};