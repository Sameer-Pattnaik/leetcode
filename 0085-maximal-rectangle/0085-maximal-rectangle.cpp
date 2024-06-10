class Solution {
public:
vector<int>nextElement(vector<int>&arr)
{
    int n=arr.size();
    vector<int>ans(n);
    stack<int>st;
    st.push(-1);
    for(int i=n-1;i>=0;i--)
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
vector<int>prevElement(vector<int>&arr)
{
    int n=arr.size();
    vector<int>ans(n);
    stack<int>st;
    st.push(-1);
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
int largestRectangleinHistogram(vector<int> &heights)
{
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
        int area=l*b;
        maxArea=max(maxArea,area);
    }
    return maxArea;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
    int n=matrix[0].size();
    vector<int>height(n,0);
    
    int maxRectangle=0;
    //int maxRectangle=INT_MIN;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]!='0')
            {
                height[j]+=1;
            }
            else
            {
                height[j]=0;
            }
            
        }
        maxRectangle=max(maxRectangle,largestRectangleinHistogram(height));
        
    }
    return maxRectangle;
    }
};