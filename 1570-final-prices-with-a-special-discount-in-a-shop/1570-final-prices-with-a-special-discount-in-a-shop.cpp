class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans;
        
      for(int i=0;i<prices.size();i++)
      {
        int cnt=0;
        for(int j=i+1;j<prices.size();j++)
        {
            if(prices[i]-prices[j]>=0)
            {
               ans.push_back(prices[i]-prices[j]);
               cnt++;
               break;
            }
        }
        if(cnt==0)
        {
            ans.push_back(prices[i]);
            cnt++;
        }
      }
      return ans;  
    }
};