class Solution {
public:
    int maxPower(string s) {
       int count=1;
       int maxCount=1;
       for(int i=0;i<s.length();i++)
       {
          if(i==0)
          {
            continue;
          }
          else if(s[i]==s[i-1])
          {
            count++;
          }
          else
          {
            maxCount=max(maxCount,count);
            count=1;
          }
       } 
        maxCount=max(maxCount,count);
       return maxCount;
    }
};