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
void reverse(vector<int>&ans,int s,int e)
{
    int n=ans.size();
    while(s<=e)
    {
        swap(ans[s],ans[e]);
        s++;
        e--;
    }
}
void insertAtTail(ListNode*&head,ListNode*&tail,int e)
{
    ListNode*temp=new ListNode(e);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>ans;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            ans.push_back(temp->val);
           temp=temp->next;
        }
        int s=left-1;
        int e=right-1;
        reverse(ans,s,e);
        ListNode*ansHead=NULL;
        ListNode*ansTail=NULL;
        for(int i=0;i<ans.size();i++)
        {
            insertAtTail(ansHead,ansTail,ans[i]);
        }
        return ansHead;

    }
};