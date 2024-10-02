class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
    int n=arr.size();
     vector<int>ans(n);
     for(int i=0;i<arr.size();i++)
     {
        ans[i]=arr[i];
     } 
     sort(ans.begin(),ans.end());
     map<int,int>mp;
     int numbering=1;
     for(int i=0;i<ans.size();i++)
     {
        if(mp.find(ans[i])==mp.end())
        {
        mp[ans[i]]=numbering;
        numbering++;
        }
     }  
     vector<int>result;
     for(int i=0;i<arr.size();i++)
     {
        result.push_back(mp[arr[i]]);
     }
     return result;
    }
};