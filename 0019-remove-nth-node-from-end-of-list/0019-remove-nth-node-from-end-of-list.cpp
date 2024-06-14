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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head=reverse(head);
        ListNode*temp=head;
        int count=0;
        if(n==1)
        {
            temp=temp->next;
            head=temp;
        }
        while(temp!=NULL && temp->next!=NULL)
        {
            count++;
            if(count==n-1)
            {
                temp->next=temp->next->next;
            }
        
            temp=temp->next;
            
            
        }
        return reverse(head);
    }
};