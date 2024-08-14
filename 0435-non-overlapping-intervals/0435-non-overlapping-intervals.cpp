class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end(),compare);
       vector<vector<int>>ans;
       int cnt=0;
       for(int i=0;i<intervals.size();i++)
       {
          if(ans.empty() || intervals[i][0]>=ans.back()[1])
          {
            ans.push_back(intervals[i]);
          }
          
          else
          {
            cnt++;
            
          }
       }
       return cnt; 
    }
};