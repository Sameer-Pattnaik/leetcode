class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(strs[i]);
        }
        int idx=0;
        vector<vector<string>>ans(mp.size());
        for(auto it:mp)
        {
            auto x=it.second;
            for(int i=0;i<x.size();i++)
            {
                 ans[idx].push_back(x[i]);
            }
            idx++;
        }
        return ans;
    }
};