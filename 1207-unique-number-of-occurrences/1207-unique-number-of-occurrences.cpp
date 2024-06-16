class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      map<int,int>mp;
      vector<int>ans;
      for(int i=0;i<arr.size();i++)
      {
        mp[arr[i]]++;
      }  
      for(auto it:mp)
      {
        ans.push_back(it.second);
      }
      sort(ans.begin(),ans.end());
      for(int i=0;i<ans.size();i++)
      {
        if(i==0)
        {
            continue;
        }
        else if(i>0 && ans[i]==ans[i-1])
        {
            return false;
        }
      }
      return true;
    }
};