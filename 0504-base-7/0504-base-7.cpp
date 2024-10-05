class Solution {
public:
    string convertToBase7(int num) {
      if(num==0)
      {
        return "0";
      }
      int num1=abs(num);
      string ans="";
      while(num1)
      {
        int rem=num1%7;
        ans+=to_string(rem);
        num1=num1/7;
      } 
      
      reverse(ans.begin(),ans.end());
      string result="";
      if(num<0)
      {
        result+="-";
      }
      for(int i=0;i<ans.length();i++)
      {
        result+=ans[i];
      }
      return result;
    }
};