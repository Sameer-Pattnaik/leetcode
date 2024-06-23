class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        vector<double>ans;
        int n=nums.size();
        while(n)
        {
        int maxNo=INT_MIN;
        int minNo=INT_MAX;
        for(int i=0;i<n;i++)
        {
            maxNo=max(maxNo,nums[i]);
            minNo=min(minNo,nums[i]);
        }
        double avg=((maxNo+minNo)/2.0);
        ans.push_back(avg);
        sort(nums.begin(),nums.end());
        nums.pop_back();
        sort(nums.begin(),nums.end(),greater<int>());
        nums.pop_back();
        n=n-2;
        }
        map<double,int>mp;
        for(int i=0;i<ans.size();i++)
        {
            mp[ans[i]]++;
        }
        int count=0;
        for(auto it:mp)
        {
            if(it.first>=0)
            {
                count++;
            }
        }
        return count;
    }
};