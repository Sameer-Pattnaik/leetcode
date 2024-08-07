class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans="";
        vector<string>output;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ' && ans.size()>0)
            {
               output.push_back(ans); 
               ans.clear();
               
            }
            else
            {
                ans+=s[i];
            }
        }
        output.push_back(ans);

    
        string sol="";
        for(int i=0;i<output.size();i++)
        {
            if(i<k)
            {
            sol+=output[i];
            sol+=" ";
            }
        }
        sol.pop_back();
        return sol;
    }
};