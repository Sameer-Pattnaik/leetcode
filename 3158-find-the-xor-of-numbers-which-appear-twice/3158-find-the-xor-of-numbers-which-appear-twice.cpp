class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
       map<int,int>mp;
       vector<int>ans;
       for(int i=0;i<nums.size();i++)
       {
        mp[nums[i]]++;
       }
       for(auto it:mp)
       {
        if(it.second >1)
        {
          ans.push_back(it.first); 
        }
       }
       int sol=0;
       for(int i=0;i<ans.size();i++)
       {
           sol^=ans[i];
       } 
       return sol;
    }
};