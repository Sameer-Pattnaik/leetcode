class Solution {
public:
    int minSwaps(string s) {
        
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='[')
            {
                st.push(s[i]);
            }
            else if(!st.empty() && s[i]==']' && st.top()=='[')
            {
                st.pop();
            }
            
        }
        return (st.size()+1)/2;
    }
};