class Solution {
public:
    void solve(int index,string digits,string ans,vector<string>&output,string mapping[])
    {
        if(index>=digits.length())
        {
            output.push_back(ans);
            return;
        }
        int num=digits[index]-'0';
        string val=mapping[num];
        for(int i=0;i<val.length();i++)
        {
            ans.push_back(val[i]);
            solve(index+1,digits,ans,output,mapping);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>output;
        if(digits.length()==0)
        {
            return output;
        }
        string ans;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;
        solve(index,digits,ans,output,mapping);
        return output;
    }
};