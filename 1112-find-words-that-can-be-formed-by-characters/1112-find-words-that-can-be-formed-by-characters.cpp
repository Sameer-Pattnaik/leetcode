class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int>mp;
        for(int i=0;i<chars.size();i++)
        {
            mp[chars[i]]++;
        }
        int sum=0;
        for(int i=0;i<words.size();i++)
        {
            bool flag=true;
            string word=words[i];
            map<char,int>mp1;
            for(int j=0;j<word.length();j++)
            {
                if(!mp[word[j]] || mp[word[j]]==mp1[word[j]])
                {
                   flag=false;
                   break;
                }
                mp1[word[j]]++;
            }
            if(flag)
            {
               sum+=word.length();
            }

        }
        return sum;
    }
};