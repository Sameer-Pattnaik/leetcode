class Solution {
public:
    string makeFancyString(string s) {
       string ans="";
       int cnt=0;
       for(int i=0;i<s.length();i++)
       {
           cnt++;
           if(s[i]!=s[i+1])
           {
            cnt=0;
           }
           else if(cnt>1)
           {
            continue;
           }
           
           
            ans+=s[i];
           
       } 
       return ans;
    }
};