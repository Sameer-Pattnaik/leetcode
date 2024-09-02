class Solution {
public:
    bool isPalindrome(string s) {
      for(int i=0;i<s.length();i++)
      {
        if(s[i]>='A' && s[i]<='Z')
        {
            s[i]=char(32+s[i]);
        }

      }
      string ans="";
      for(int i=0;i<s.length();i++)
      {
         if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
         {
            ans.push_back(s[i]);
         }
         
      } 
      int i=0;
      int j=ans.length()-1;
      while(i<=j)
      {
        if(ans[i]!=ans[j])
        {
            return false;
        }
        i++;
        j--;
      }
      return true; 
    }
};