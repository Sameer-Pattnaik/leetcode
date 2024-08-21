class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>ans1;
        string word="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                ans1.push_back(word);
                word.clear();
            }
            else
            {
               word+=s[i];
            }
        }
        ans1.push_back(word);
        map<char,string>m1;
        map<string,char>m2;
        if(pattern.length()!=ans1.size())
        {
            return false;
        }
        for(int i=0;i<ans1.size();i++)
        {
            if(m1.find(pattern[i])!=m1.end())
            {
                if(m1[pattern[i]]!=ans1[i])
                {
                    return false;
                }
            }
            else if(m2.find(ans1[i])!=m2.end())
            {
                if(m2[ans1[i]]!=pattern[i])
                {
                    return false;
                }
            }
            else
            {
                m1[pattern[i]]=ans1[i];
                m2[ans1[i]]=pattern[i];
            }
        }
        
        return true;
    }
};