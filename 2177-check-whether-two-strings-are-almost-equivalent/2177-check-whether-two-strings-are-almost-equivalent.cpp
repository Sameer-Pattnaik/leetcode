class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
       vector<int>mp1(26,0);
       vector<int>mp2(26,0);
       for(int i=0;i<word1.length();i++)
       {
           mp1[word1[i]-'a']++;
       }
       for(int i=0;i<word2.length();i++)
       {
           mp2[word2[i]-'a']++;
       }
       for(int i=0;i<mp1.size();i++)
       {
          if(abs(mp1[i]-mp2[i])>3)
          {
            return false;
          }
       }
       return true;
    }
};