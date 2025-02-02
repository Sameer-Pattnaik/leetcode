class Solution {
public:
    string sortSentence(string s) {
        vector<string>ans(9);
        string word="";
        int index=0;
        for(int i=0;i<s.length();i++)
        {
           if(s[i]==' ')
           {
             ans[index-1]=word;
             word.clear();
             index=0;
           }
           else if(s[i]>='0' && s[i]<='9')
           {
            index=s[i]-'0';
           }
           else{
            word+=s[i];
           }
        }
        ans[index-1]=word;
        word.clear();
        string sentence="";
        for(int i=0;i<9;i++)
        {
            if(!ans[i].empty())
            {
                sentence+=ans[i];
                sentence+=" ";
            }
            
        }
        sentence.pop_back();
        return sentence;
    }
};