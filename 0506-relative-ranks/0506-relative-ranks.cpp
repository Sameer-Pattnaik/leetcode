class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<int>ans(n);
        for(int i=0;i<score.size();i++)
        {
            ans[i]=score[i];
        }
        sort(ans.begin(),ans.end(),greater<int>());
        map<int,string>mp;
        for(int i=0;i<ans.size();i++)
        {
            if(i==0)
            {
               mp[ans[i]]="Gold Medal";
            }
            else if(i==1)
            {
                mp[ans[i]]="Silver Medal";
            }
            else if(i==2)
            {
                 mp[ans[2]]="Bronze Medal";
            }
            else
            {
            mp[ans[i]]=to_string(i+1);
            }
        }
        vector<string>result;
        for(int i=0;i<n;i++)
        {
            result.push_back(mp[score[i]]);
        }
        return result;
    }
};