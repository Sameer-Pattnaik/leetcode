class Solution {
public:
    int evaluate(string ch, int val1, int val2){
        if(ch=="+") return val1+val2;
        if(ch=="-") return val1-val2;
        if(ch=="*") return val1*val2;
        return val1/val2;
    }
    
    int evalRPN(vector<string>& s) {
        stack<int> val;
        for(int i=0;i<s.size();i++){
            if(s[i]=="+" or s[i]=="/" or s[i]=="-" or s[i]=="*"){
                int val2=val.top();
                val.pop();
                int val1=val.top();
                val.pop();
                int ans=evaluate(s[i],val1,val2);     
                val.push(ans);
            }
            else val.push(stoi(s[i]));
        }
        return val.top();
        

    }
};