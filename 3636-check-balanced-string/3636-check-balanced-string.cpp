class Solution {
public:
    bool isBalanced(string num) {
        stack<int>st1;
        stack<int>st2;
        for(int i=0;i<num.length();i++)
        {
            if(i%2==0)
            {
                st1.push(num[i]-'0');
            }
            else
            {
                st2.push(num[i]-'0');
            }
        }
        int sum1=0;
        int sum2=0;
        while(!st1.empty())
        {
            sum1+=st1.top();
            st1.pop();
        }
        while(!st2.empty())
        {
            sum2+=st2.top();
            st2.pop();
        }
        if(sum1==sum2)
        {
            return true;
        }
        return false;
    }
};