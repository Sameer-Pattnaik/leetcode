class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int n=nums.size();
        vector<int>solution;
        map<int,int>mp;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==key)
            {
                solution.push_back(i+1);
            
            }
        }
        vector<int>result;
        for(int i=0;i<solution.size();i++)
        {
           result.push_back(nums[solution[i]]);
        }
        for(int i=0;i<result.size();i++)
        {
            cout<<result[i]<<" ";
        }
        for(int i=0;i<result.size();i++)
        {
           mp[result[i]]++;
        }
        int maxNo=0;
        int target=0;
        for(auto it:mp)
        {
           if(it.second>maxNo)
           {
              maxNo=max(maxNo,it.second);
              target=it.first;
           }
        }
        
      return target;
    }
};