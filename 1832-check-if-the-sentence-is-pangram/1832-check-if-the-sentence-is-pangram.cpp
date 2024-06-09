class Solution {
public:
    bool checkIfPangram(string sentence) {
      vector<int>ans(26,0);
      for(int i=0;i<sentence.length();i++)
      {
        ans[sentence[i]-'a']++;
      }
      for(int i=0;i<26;i++)
      {
        if(ans[i]<1)
        {
            return false;
        }
      }
      return true;  
    }
};