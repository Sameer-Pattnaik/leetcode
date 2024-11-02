class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string>sol;
        string ans="";
        for(int i=0;i<sentence.length();i++)
        {
            if(sentence[i]==' ')
            {
                sol.push_back(ans);
                ans.clear();
            }
            else
            {
                ans+=sentence[i];
            }
        }
        sol.push_back(ans);
        if(sol.size()==1)
        {
            string word=sol[0];
            if(word[word.size()-1]==word[0])
            {
            return true;
            }
            return false;
        }
        for(int i=0;i<sol.size()-1;i++)
        {
            string word1=sol[i];
            string word2=sol[i+1];
            if(word1[word1.length()-1]!=word2[0])
            {
                return false;
            }
        }
        string sen1=sol[0];
        string sen2=sol[sol.size()-1];
        if(sen1[0]==sen2[sen2.length()-1])
        {
        return true;
        }
        return false;
    }
};