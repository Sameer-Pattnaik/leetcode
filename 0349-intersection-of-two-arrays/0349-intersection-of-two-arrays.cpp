class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>ans;
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
                i++;
            }
            else if(nums1[i]==nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else 
            {
                j++;
            }
        }
        vector<int>result;
        if(ans.size()>0)
        {
        result.push_back(ans[0]);
        for(int i=0;i<ans.size();i++)
        {
            if(i==0)
            {
                continue;
            }
            else if(ans[i]==ans[i-1])
            {
                continue;
            }
            else
            {
                result.push_back(ans[i]);
            }
        }
        return result;
        }
        return result;
    }
};