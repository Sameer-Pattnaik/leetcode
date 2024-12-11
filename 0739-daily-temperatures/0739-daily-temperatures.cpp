class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        vector<int>ans(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++)
        {
           while(!st.empty() && temperatures[i]>temperatures[st.top()])
           {
            int index=st.top();
            st.pop();
            ans[index]=i-index;
           }
           st.push(i);
        }
        return ans;
    }
};