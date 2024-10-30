class Solution {
public:
    bool detectCapitalUse(string word) {
        int count1=0;
        int count2=0;
       for(int i=0;i<word.length();i++)
       {
          if(word[i]>='a' && word[i]<='z')
          {
            count1++;
          }
          else if(word[i]>='A' && word[i]<='Z')
          {
            count2++;
          }
       }
       if(count1==word.length() || count2==word.length())
       {
        return true;
       } 
       if(count1==word.length()-1 && word[0]>='A' && word[0]<='Z')
       {
        return true;
       }
       return false;
    }
};