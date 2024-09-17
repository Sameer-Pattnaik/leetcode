class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>sentence;
        string word="";
        vector<string>ans;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]==' ')
            {
                sentence.push_back(word);
                word.clear();
            }
            else
            {
                word+=s1[i];
            }
        }
        
        sentence.push_back(word);
        word.clear();
        for(int i=0;i<s2.length();i++)
        {
            if(s2[i]==' ')
            {
                sentence.push_back(word);
                word.clear();
            }
            else
            {
                word+=s2[i];
            }
        }
        sentence.push_back(word);
        map<string,int>mp;
        for(int i=0;i<sentence.size();i++)
        {
           mp[sentence[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second==1)
            {
               ans.push_back(it.first);
            }
        }
        return ans;
    }
};