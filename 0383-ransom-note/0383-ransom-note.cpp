class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>mp1(26,0);
        vector<int>mp2(26,0);
         for(int i=0;i<ransomNote.length();i++)
         {
            mp1[ransomNote[i]-'a']++;
         }
         for(int i=0;i<magazine.length();i++)
         {
            mp2[magazine[i]-'a']++;
         }
       for(int i=0;i<magazine.length();i++)
       {
        if(mp2[magazine[i]-'a']>0)
        {
        mp1[magazine[i]-'a']--;
        }
       }
       for(int i=0;i<mp1.size();i++)
       {
        if(mp1[i]>0)
        {
            return false;
        }
       }
       return true;
    }
};