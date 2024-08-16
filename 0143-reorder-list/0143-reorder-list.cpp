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

    ListNode*reverse(ListNode* head)
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
    void reorderList(ListNode* head) {
        ListNode* firstNode=head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
    {   
        slow=slow->next;
        fast=fast->next->next;
    }
        ListNode* secondNode=reverse(slow->next);
        slow->next=NULL;
        ListNode* temp=NULL;
        ListNode* curr=NULL;
        while(secondNode!=NULL)
        {
            temp=firstNode->next;
            curr=secondNode->next;
            firstNode->next=secondNode;
            secondNode->next=temp;
            firstNode=temp;
            secondNode=curr;
        }
        

    }
};