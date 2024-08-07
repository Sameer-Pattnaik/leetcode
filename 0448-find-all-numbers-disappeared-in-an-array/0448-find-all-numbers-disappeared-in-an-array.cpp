class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
           ans.push_back(it.first);
        }
        vector<int>result;
        for(int i=0;i<nums.size();i++)
        {
            result.push_back(i+1);
        }
        int i=0;
        int j=0;
        vector<int>target;
        while(i<ans.size() && j<result.size())
        {
            if(ans[i]==result[j])
            {
                i++;
                j++;
            }
            else
            {
                target.push_back(result[j]);
                j++;
            }
        }
        while(j<result.size())
        {
            target.push_back(result[j]);
            j++;
        }
      return target;
    }
};