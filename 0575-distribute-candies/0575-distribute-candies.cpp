class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
    vector<int>ans;
    int n=candyType.size();
    int m=n/2;
    sort(candyType.begin(),candyType.end());
    ans.push_back(candyType[0]);
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            continue;
        }
        else if(candyType[i]==candyType[i-1] && i>0)
        {
             continue;
        }
        else
        {
            ans.push_back(candyType[i]);
        }
    }
    if(ans.size()<m)
    {
        return ans.size();
    }
    return m;
    }
};