class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        reverse(s.begin(),s.end());
        while(s.size()!=1){
            ans++;
            int i=0;
            if(s[i]=='1'){
            while(s[i]!='0' && i<s.size()){
                s[i]='0';
                i++;
            }
            if(i==s.size()){
                s+='1';
            }
            else{
                s[i]='1';
            }
            }
            else{
                string temp=s.substr(1,s.length()-1);
                s=temp;
            }

        }
      
        return ans;
    }
};