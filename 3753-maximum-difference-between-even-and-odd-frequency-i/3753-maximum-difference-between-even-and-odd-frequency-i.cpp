class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mp;
       for(int i=0;i<s.length();i++)
       {
        mp[s[i]]++;
       } 
       int maxi=INT_MIN;
       int mini=INT_MAX;
       int odd=0;
       int even=0;
      
       for(int i=0;i<mp.size();i++)
       {
        if(mp[i]%2)
        {
          maxi=max(maxi,mp[i]);
        }
        else if(mp[i]%2==0 && mp[i]!=0)
        {
            mini=min(mini,mp[i]);
        }
       }
       odd=maxi;
      
       even=mini;
       
       return odd-even;
    }
};