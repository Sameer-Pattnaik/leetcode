class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       vector<int>ans;
       
       for(int i=0;i<arr2.size();i++)
       {
        for(int j=0;j<arr1.size();j++)
        {
            if(arr2[i]==arr1[j])
            {
                ans.push_back(arr1[j]);
            }
        }
       }
      sort(arr1.begin(),arr1.end());
      sort(arr2.begin(),arr2.end());
      vector<int>result;
      int i=0;
      int j=0;
      while(i<arr1.size()-1 && j<arr2.size())
      {
        if(arr1[i]!=arr1[i+1] && arr1[i]==arr2[j])
        {
            i++;
            j++;
        }
        else if(arr1[i]==arr1[i+1] && arr1[i]==arr2[j])
        {
            i++;
        }
        else
        {
            result.push_back(arr1[i]);
            i++;
        }
      }
      while(i<arr1.size() && j<arr2.size())
      {
        if(arr1[i]==arr2[j])
        {
            i++;
            j++;
        }
      }
      while(i<arr1.size())
      {
        result.push_back(arr1[i]);
        i++;
      }      
      for(int i=0;i<result.size();i++)
      {
        ans.push_back(result[i]);
      }
        
       return ans;
    }
};