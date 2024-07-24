class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        
        int sum=0;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i]=="C" && !st.empty())
            {
                st.pop();
            }
            else if(operations[i]=="D" && !st.empty())
            {

                st.push(2*st.top());
            }
            else if(operations[i]=="+" && !st.empty())
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int sum=a+b;
                st.push(b);
                st.push(a);
                st.push(a+b);
        
            }
            else
            {
                st.push(stoi(operations[i]));
            }
        }
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};