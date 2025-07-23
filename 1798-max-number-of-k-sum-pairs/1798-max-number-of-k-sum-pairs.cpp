class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       int ans = 0;
       for(int x:nums){
        int target = k - x;
        if(mp[target] > 0){
            mp[target]--;
            ans ++;
        }else{
            mp[x]++;
        }
       }
       return ans;
    }
};