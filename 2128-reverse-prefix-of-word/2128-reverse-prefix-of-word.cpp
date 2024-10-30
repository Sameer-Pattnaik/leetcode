class Solution {
public:
    string reversePrefix(string word, char ch) {
       stack<char>st;
       string ans="";
       int i=0;
       bool flag=false;
       for(int i=0;i<word.length();i++)
       {
          if(word[i]==ch)
          {
            flag=true;
          }
       }
       if(flag)
       {
       while(i<word.length())
       {
           st.push(word[i]);
           
           if(word[i]==ch)
           {
            break;
           }
        i++;
       }
       i++;
       string sol="";
       while(!st.empty())
       {
        sol+=st.top();
        st.pop();
       }
       while(i<word.length())
       {
        ans+=word[i];
        i++;
       }
       return sol+ans;
       }
       return word;
    }
};