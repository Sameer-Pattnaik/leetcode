class Solution {
public:
    string reverseOnlyLetters(string s) {
       string ans="";
       for(int i=0;i<s.length();i++)
       {
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a'&& s[i]<='z'))
        {
          ans+=s[i];
        }
       } 
       reverse(ans.begin(),ans.end());
       int i=0;
       int j=0;
       while(i<s.length() && j<ans.length())
       {
           if((s[i]>='A' && s[i]<='Z')||(s[i]>='a'&& s[i]<='z'))
           {
            s[i]=ans[j];
            j++;
           }
           i++;
           
       }
       return s;
    }
};