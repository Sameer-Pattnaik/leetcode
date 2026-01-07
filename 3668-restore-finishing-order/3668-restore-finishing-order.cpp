class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        map<int,int>mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]]++;
        }
        for(int i=0;i<friends.size();i++){
            mp[friends[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<order.size();i++){
            if(mp[order[i]]==2){
                ans.push_back(order[i]);
            }
        }
        return ans;
    }
};