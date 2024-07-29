/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int n=ans.size();
        stack<int>st;
        vector<int>output(n,0);
        for(int i=n-1;i>=0;i--)
        {
            int curr=ans[i];
            while(!st.empty() && st.top()<=curr)
            {
                st.pop();
            }
            if(!st.empty())
            {
                output[i]=st.top();
            }
            st.push(curr);
        }
        return output;
    }
};