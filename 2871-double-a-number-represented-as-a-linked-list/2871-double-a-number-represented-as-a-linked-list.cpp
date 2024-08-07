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
ListNode*reverse(ListNode*&head)
{
    ListNode*prev=NULL;
    ListNode*curr=head;
    ListNode*next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
    ListNode* doubleIt(ListNode* head) {
       head=reverse(head);
       ListNode*ansHead=NULL;
       ListNode*ansTail=NULL;
       int carry=0;
       ListNode*temp=head;
       
       while(temp!=NULL)
       {
        int ans=carry+(temp->val*2);
        int digit=ans%10;
        insertAtTail(ansHead,ansTail,digit);
        carry=ans/10;
        temp=temp->next;
       } 
       while(carry!=0)
       {
        int ans=carry;
        int digit=ans%10;
        insertAtTail(ansHead,ansTail,digit);
        carry=ans/10;
       }
       ansHead=reverse(ansHead);
       return ansHead;
    }
};