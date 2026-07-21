class Solution {
public:
    int maxDepth(string s) {
        int p=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                p++;
            }
            else if(s[i]==')'){
                p--;
            }
            ans=max(ans,p);
        }
        return ans;
    }
};