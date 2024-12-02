class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
     vector<string>ans;
     string word;
     for(int i=0;i<sentence.length();i++)
     {
        if(sentence[i]==' ')
        {
            ans.push_back(word);
            word.clear();
        }
        else
        {
            word+=sentence[i];
        }
     }
     ans.push_back(word);
     int sol=-1;
     int cnt=0;
     for(auto it:ans)
     {
        cnt++;
        if(it.find(searchWord)==0)
        {
            sol=cnt;
            break;
        }
     }
     return sol;
    }
};