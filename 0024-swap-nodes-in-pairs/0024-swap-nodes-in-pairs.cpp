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
    ListNode* swapPairs(ListNode* head) {
        int k=2;
        int count=0;
        ListNode*prev=NULL;
        ListNode*temp=head;
        ListNode*curr=NULL;
        while(temp!=NULL && count<k)
        {
            curr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
            count++;
        }
        if(temp!=NULL)
        {
            head->next=swapPairs(curr);
        }
        return prev;
    }
};