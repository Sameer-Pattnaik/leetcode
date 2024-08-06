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
ListNode*reverse(ListNode*&head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
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
void insertAttail(ListNode*&head,ListNode*&tail,int e)
{
    ListNode*temp=new ListNode(e);
    if(head==NULL && tail==NULL)
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
ListNode*add(ListNode*&head1,ListNode*&head2)
{
    ListNode*temp=head1;
    ListNode*curr=head2;
    ListNode*ansHead=NULL;
    ListNode*ansTail=NULL;
    int carry=0;
    while(temp!=NULL && curr!=NULL)
    {
        
        int sum=carry+temp->val+curr->val;
        int digit=sum%10;
        carry=sum/10;
        insertAttail(ansHead,ansTail,digit);
        temp=temp->next;
        curr=curr->next;
    }
    while(temp!=NULL)
    {
        int sum=carry+temp->val;
        int digit=sum%10;
        carry=sum/10;
        insertAttail(ansHead,ansTail,digit);
        temp=temp->next;
    }
    while(curr!=NULL)
    {
        
        int sum=carry+curr->val;
        int digit=sum%10;
        carry=sum/10;
        insertAttail(ansHead,ansTail,digit);
        curr=curr->next;
    }
    while(carry!=0)
    {
        int sum=carry;
        int digit=sum%10;
        carry=sum/10;
        insertAttail(ansHead,ansTail,digit);
    }
    return ansHead;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //l1=reverse(l1);
    //l2=reverse(l2);
    ListNode*addList=add(l1,l2);
    
    return addList;
    }
};