class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
       string ans="";
       for(int i=0;i<words.size();i++)
       {
          ans+=words[i][0];
       }
       int i=0;
       int j=0;
       if(ans.length()!=s.length())
       {
        return false;
       }
       while(i<ans.length() && j<s.length())
       {
          if(ans[i]!=s[j])
          {
            return false;
          }
          i++;
          j++;
       }
       return true; 
    }
};