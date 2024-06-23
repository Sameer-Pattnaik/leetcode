class Solution {
public:
    double trimMean(vector<int>& arr) {
      int sol=arr.size()*0.05;  
      while(sol)
      {
        sort(arr.begin(),arr.end());
        arr.pop_back();
        sort(arr.begin(),arr.end(),greater<int>());
        arr.pop_back();
        sol--;
      }
      double sum=0;
      for(int i=0;i<arr.size();i++)
      {
          sum+=arr[i];
      }
      double n=arr.size();
      double result=sum/n;
      return result;
    }
};