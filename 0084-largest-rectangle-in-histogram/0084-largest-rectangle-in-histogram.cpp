class Solution {
public:
vector<int>prevElement(vector<int>&arr)
{
    stack<int>st;
    st.push(-1);
    
    int n=arr.size();
    vector<int>ans(n);
    for(int i=0;i<n;i++)
    {
        int curr=arr[i];
        while(st.top()!=-1 && arr[st.top()]>=curr)
        {
            st.pop();
        }
    ans[i]=st.top();
    st.push(i);
    }
    return ans;
}
vector<int>nextElement(vector<int>&arr)
{
    stack<int>st;
    st.push(-1);
    
    int n=arr.size();
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--)
    {
        int curr=arr[i];
        while(st.top()!=-1 && arr[st.top()]>curr)
        {
            st.pop();
        }
    ans[i]=st.top();
    st.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n);
        next=nextElement(heights);
        vector<int>prev(n);
        prev=prevElement(heights);
        int maxArea=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l=heights[i];
            if(next[i]==-1)
            {
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int newArea=l*b;
            maxArea=max(maxArea,newArea);
        } 
        return maxArea; 
    }
};