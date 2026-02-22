class Solution {
public:
    int binaryGap(int n) {
      vector<int>ans;
      while(n)
      {
        int rem=n%2;
        ans.push_back(rem);
        n=n/2;
      }
      reverse(ans.begin(),ans.end());  
      int i=0;
      int maxCnt=0;
      for(int j=0;j<ans.size();j++)
      {
        if(j==0)
        {
            continue;
        }
        else if(ans[j]==1 && j>0){
           maxCnt=max(maxCnt,j-i);
           i=j;
        }
      }
      return maxCnt;
    }
};