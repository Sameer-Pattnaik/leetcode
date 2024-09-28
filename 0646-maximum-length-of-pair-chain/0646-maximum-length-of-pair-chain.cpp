class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2)
    {
        return v1[1]<v2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int cnt=1;
        int ansEnd=pairs[0][1];
        for(int i=1;i<pairs.size();i++)
        {
            if(ansEnd<pairs[i][0])
            {
                cnt++;
                ansEnd=pairs[i][1];
            }
        }
        return cnt;
    }
};