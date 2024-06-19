class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
       map<int,string>mp;
       vector<string>ans;
       
       for(int i=0;i<names.size();i++)
       {
        mp[heights[i]]=names[i];
       }
       for(auto it:mp)
       {
          ans.push_back(it.second);
       }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};