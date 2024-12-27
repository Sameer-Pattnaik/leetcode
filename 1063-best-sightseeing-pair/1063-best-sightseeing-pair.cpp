class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        if(values.size()<2)
        {
            return values[0]+values[1]+0-1;
        }
        vector<int>ans(values.size());
        ans[values.size()-1]=values[values.size()-1]-(values.size()-1);
        for(int i=values.size()-2;i>=0;i--)
        {
            ans[i]=max(ans[i+1],values[i]-i);
        }
        int maxScore=INT_MIN;
        for(int i=0;i<values.size()-1;i++)
        {
            maxScore=max(maxScore,values[i]+i+ans[i+1]);
        }
        return maxScore;
    }
};