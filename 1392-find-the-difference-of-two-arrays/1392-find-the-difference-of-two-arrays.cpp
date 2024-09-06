class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
       vector<int>output1;
       vector<int>output2;
       vector<vector<int>>ans;
       map<int,int>mp1;
       map<int,int>mp2;
       for(int i=0;i<nums1.size();i++)
       {
          mp1[nums1[i]]++;
       }
       for(auto it:mp1)
       {
        output1.push_back(it.first);
       }
       for(int i=0;i<nums2.size();i++)
       {
        mp2[nums2[i]]++;
       }
       for(auto it:mp2)
       {
        output2.push_back(it.first);
       }
       vector<int>sol1;
       vector<int>sol2;
       bool cnt1=false;
       bool cnt2=false;
       for(int i=0;i<output1.size();i++)
       {
        for(int j=0;j<output2.size();j++)
        {
            if(output1[i]==output2[j])
            {
                cnt1=true;
            }
        }
        if(cnt1==false)
        {
        sol1.push_back(output1[i]);
        }
        cnt1=false;
       }
       for(int i=0;i<output2.size();i++)
       {
        for(int j=0;j<output1.size();j++)
        {
            if(output2[i]==output1[j])
            {
                cnt2=true;
            }
        }
        if(cnt2==false)
        {
        sol2.push_back(output2[i]);
        }
        cnt2=false;
       }
       ans.push_back(sol1);
       ans.push_back(sol2);
       return ans;
    }
};