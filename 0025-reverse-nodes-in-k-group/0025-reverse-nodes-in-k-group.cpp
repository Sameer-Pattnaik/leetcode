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
    int count(ListNode* head){
        int n=0;
        while(head){
            head=head->next;
            n++;
        }
        return n;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int num=count(head);
        if(num<k)
        {
            return head;
        }
   ListNode*prev=NULL;
   ListNode*curr=head;
   ListNode*next=NULL;
   int count=0;
   while(curr!=NULL && count<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
        
    
    if(curr!=NULL)
    {
        head->next=reverseKGroup(curr,k);
    }
    return prev; 
    }
};