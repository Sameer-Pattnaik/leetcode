class Solution {
public:
    string clearDigits(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                st.push(s[i]);
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                st.pop();
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        if(ans.size())
        {
           reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};