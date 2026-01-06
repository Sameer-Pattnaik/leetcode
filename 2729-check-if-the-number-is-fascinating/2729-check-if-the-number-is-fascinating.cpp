class Solution {
public:
    bool isFascinating(int n) {
        string ans="";
        int i=3;
        while(i){
            ans+=to_string(n*i);
            i--;
        }
        cout<<ans;

        vector<int>visited(10,0);
        visited[0]=1;
        for(int i=0;i<ans.size();i++){
             if(!visited[ans[i]-'0']){
                visited[ans[i]-'0']=1;
                
             }
             else{
                return false;
             }
        }
        return true;
    }
};