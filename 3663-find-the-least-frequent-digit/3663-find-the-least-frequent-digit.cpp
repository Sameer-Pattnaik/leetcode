class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string ans=to_string(n);
        map<int,int>mp;
        for(int i=0;i<ans.size();i++){
          mp[ans[i]-'0']++;
        }
        int mini=INT_MAX;
        vector<int>sol;
        for(auto it:mp){
            if(it.second<mini){
                mini=it.second;
            }
        }
        for(auto it:mp){
            if(it.second==mini){
                sol.push_back(it.first);
            }
        }
        if(sol.size()>1){
            return sol[0];
        }
        return sol[0];
    }
};