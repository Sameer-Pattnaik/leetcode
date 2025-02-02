class Solution {
public:
    bool checkString(string s) {
        int i=0;
        int j=1;
        bool flag=false;
        while(j<s.length())
        {
            if((s[i]=='b' && s[j]=='a') && flag==false)
            {
                return false;
            }
            if((s[i]=='a' && s[j]=='b')&& flag==false)
            {
                flag=true;
            }
            else if(((s[i]=='a' && s[j]=='b') || (s[i]=='b' && s[j]=='a')) && flag==true)
            {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};