class Solution {
public:
    int calculate(string s) {
        int number=0;
        int sign=1;
        int res=0;
        stack<int>eval;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                number=number*10+(s[i]-'0');
            }
            else if(s[i]=='+' || s[i]=='-')
            {
                res+=number*sign;
                if(s[i]=='-')
                {
                    sign=-1;
                }
                else{
                    sign=1;
                }
                number=0;
            }
            else if(s[i]=='(')
            {
                eval.push(res);
                eval.push(sign);
                res=0;
                sign=1;
            }
            else if(s[i]==')')
            {
                res+=number*sign;
                res*=eval.top();
                eval.pop();
                res+=eval.top();
                eval.pop();
                number=0;
            }
        }
        return res+number*sign;
    }
};