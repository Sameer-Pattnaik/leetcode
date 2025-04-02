class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        int i=0;

        while(i<n){
            int j=i;
            int a = nums[i], b = nums[j];

            while(j+1<n && nums[j]+1 == nums[j+1]){
                j++;
                b=nums[j];
            }
            
            if(a==b) ans.push_back(to_string(a));
            else     ans.push_back(to_string(a) + "->" + to_string(b));

            i=j+1;

        }
        return ans;
    }
};