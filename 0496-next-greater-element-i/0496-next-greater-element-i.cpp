class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums2.size(),0);
        stack<int>st;
        st.push(-1);
        map<int,int>mp;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            int curr=nums2[i];
            while(curr>st.top() && st.top()!=-1)
            {
                st.pop();
            }
            ans[i]=st.top();
            mp[nums2[i]]=ans[i];
            st.push(curr);
        }
        vector<int>result;
        for(int i=0;i<nums1.size();i++)
        {
            result.push_back(mp[nums1[i]]);
        }
        return result;
    }
};