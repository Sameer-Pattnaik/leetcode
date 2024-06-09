class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        vector<string>ans;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                temp.clear();
            }
            else
            {
                temp+=s[i];
            }
        }
        reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                temp.clear();
                for(int i=0;i<ans.size();i++)
                {
                    temp+=ans[i];
                    temp+=" ";
                }
                temp.pop_back();
                return temp;
    }
};