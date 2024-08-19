class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='#' && !st.empty())
            {
                st.pop();
            }
            else if(s[i]=='#' && st.empty())
            {
                continue;
            }
            else
            {
                st.push(s[i]);
            }
        }
        string s1="";
        while(!st.empty())
        {
            s1+=st.top();
            st.pop();
        }
        for(int i=0;i<t.length();i++)
        {
            if(t[i]=='#' && !st.empty())
            {
                st.pop();
            }
            else if(t[i]=='#' && st.empty())
            {
                continue;
            }
            else
            {
                st.push(t[i]);
            }
        }
        string s2="";
        while(!st.empty())
        {
            s2+=st.top();
            st.pop();
        }
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        cout<<s1<<" "<<s2;
        
        if(s1.length()>=s2.length())
        {
            for(int i=0;i<s1.length();i++)
            {
                if(s1[i]!=s2[i])
                {
                    return false;
                }
            }
        }
        else 
        {
            for(int i=0;i<s2.length();i++)
            {
                if(s2[i]!=s1[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};