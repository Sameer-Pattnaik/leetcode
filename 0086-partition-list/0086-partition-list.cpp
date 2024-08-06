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
void insertAtHead(ListNode*&head,ListNode*&tail,int e)
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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode*ansHead1=NULL;
        ListNode*ansTail1=NULL;
        ListNode*ansHead2=NULL;
        ListNode*ansTail2=NULL;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            if(temp->val<x)
            {
                insertAtHead(ansHead1,ansTail1,temp->val);
            }
            else
            {
                insertAtHead(ansHead2,ansTail2,temp->val);
            }
            temp=temp->next;
        }
        if(ansTail1!=NULL)
        {
        ansTail1->next=ansHead2;
        }
        else
        {
            return ansHead2;
        }
        return ansHead1;
    }
};