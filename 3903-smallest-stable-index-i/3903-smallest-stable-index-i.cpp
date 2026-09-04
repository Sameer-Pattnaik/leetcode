class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int idx1=1;
        int idx2=0;
        int index=0;
        while(index<nums.size()){
            int mini=INT_MAX;
            int maxi=INT_MIN;
            for(int i=0;i<idx1;i++){
                 maxi=max(maxi,nums[i]); 
            }
            for(int j=idx2;j<nums.size();j++){
                 mini=min(mini,nums[j]); 
                 
            }
            if(maxi-mini<=k){
                return index;
            }
            index++;
            idx1++;
            idx2++;
        }
        return -1;
    }
};