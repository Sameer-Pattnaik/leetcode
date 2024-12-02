class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
      int cnt=0;
      for(int i=0;i<words.size();i++)
      {
        if(s.find(words[i])==0)
        {
            cnt++;
        }
      }
      return cnt;  
    }
};