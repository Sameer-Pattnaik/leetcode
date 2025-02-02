class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int>sol;
        int ope=0;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
               ans=ope*10+(s[i]-'0');
               ope=ans; 
            }
            else if(s[i]==' ')
            {
                if(ans>0)
                {
                   sol.push_back(ans);
                }
                ope=0;
                ans=0;
            }
        }
        if(ans>0)
        {
            sol.push_back(ans);
            ans=0;
        }
        for(int i=0;i<sol.size();i++)
        {
            cout<<sol[i]<<" ";
        }
        for(int i=0;i<sol.size()-1;i++)
        {
           if(sol[i]>=sol[i+1])
           {
              return false;
           }
        }
        return true;
    }
};