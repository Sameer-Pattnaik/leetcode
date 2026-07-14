class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        vector<pair<string,int>>ans;
        for(auto m:mp){
            ans.push_back(m);
        }
        sort(ans.begin(),ans.end(),[](auto &a,auto &b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second>b.second;
        });
        vector<string>sol;
        int i=0;
        while(k--){
            sol.push_back(ans[i].first);
            i++;
        }
        return sol;
    }
};