class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        solve(0,0,"",n,res);
        return res;
    }
    void solve(int index1,int index2,string sol,int n,vector<string>&res)
    {
        if(index1==index2 && index1+index2==n*2)
        {
            res.push_back(sol);
            return;
        }
        if(index1<n)
        {
            solve(index1+1,index2,sol+"(",n,res);
        }
        if(index2<index1)
        {
            solve(index1,index2+1,sol+")",n,res);
        }
    } 
};