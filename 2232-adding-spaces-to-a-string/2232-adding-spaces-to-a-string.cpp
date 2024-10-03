class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int idx=0;
        int i=0;
       while(idx<spaces.size())
       {
          if(i==spaces[idx])
          {
            ans+=" ";
            idx++;
          }
            ans+=s[i];
            i++;
        }
        while(i<s.length())
        {
            ans+=s[i];
            i++;
        }
        return ans; 
    }
};