class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int cnt1=0;
        int cnt2=0;
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    cnt1++;
                    break;
                }
            }
        }
        for(int i=0;i<nums2.size();i++)
        {
            for(int j=0;j<nums1.size();j++)
            {
                if(nums2[i]==nums1[j])
                {
                    cnt2++;
                    break;
                }
            }
        }
        ans.push_back(cnt1);
        ans.push_back(cnt2);
        return ans;

    }
};