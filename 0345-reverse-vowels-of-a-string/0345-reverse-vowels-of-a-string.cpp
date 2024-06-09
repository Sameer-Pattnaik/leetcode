class Solution {
public:
    string reverseVowels(string s) {
        string temp="";
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if((s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')||(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'))
            {
                 temp.push_back(s[i]);
            }
        }
        reverse(temp.begin(),temp.end());
        int i=0;
        int j=0;
        while(i<s.length())
        {
            if((s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')||(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'))
            {
                ans+=temp[j];
                j++;
            }
            else
            {
                ans+=s[i];
            }
            i++;
        }
        
        return ans;

    }
};