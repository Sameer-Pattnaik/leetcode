class Solution {
public:
    int myAtoi(string s) {
      bool flag=false;
      long ans=0;
      int sign=1;
      for(int i=0;i<s.length();i++)
      {
        if(flag==false && (s[i]==' ' || s[i]=='0'))
        {
            if(s[i]=='0')
            {
                flag=true;
            }
            continue;
        }
        else if(flag==false && (s[i]=='-' || s[i]=='+'))
        {
            
            if(s[i]=='-')
            {
            sign=-1;
            }
            flag=true;
        }
        else if(!(s[i]>='0' && s[i]<='9'))
        {
            break;
        }
        else
        {
            flag=true;
            ans*=10;
            ans+=(s[i]-'0')*sign;
            if(ans<INT_MIN)
            {
                return INT_MIN;
            }
            if(ans>INT_MAX)
            {
                return INT_MAX;
            }
        }
      }
      return ans;  
    }
};