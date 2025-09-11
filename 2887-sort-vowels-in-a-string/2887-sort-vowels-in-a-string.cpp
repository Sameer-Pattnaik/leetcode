class Solution {
public:
    string sortVowels(string s) {
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            if((s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')||(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'))
            {
                temp+=s[i];
            }
        }
        sort(temp.begin(),temp.end());
        string ans="";
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