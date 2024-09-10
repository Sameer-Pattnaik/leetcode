class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        map<int,char>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[indices[i]]=s[i];
        }
        string ans="";
        for(auto it:mp)
        {
           ans+=it.second;
        }
        return ans;
    }
};