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
ListNode* solve(ListNode*list1,ListNode*list2)
{
    ListNode*prev=list1;
    ListNode*curr=prev->next;
    ListNode*temp=list2;
    ListNode*next=NULL;
    while(temp!=NULL && curr!=NULL)
    {
      if((temp->val>=prev->val)&&(curr->val>=temp->val))
      {
          next=temp->next;
          prev->next=temp;
          temp->next=curr;
          prev=temp;
          temp=next;
      }
      else
      {
          prev=curr;
          curr=curr->next;
          if(curr==NULL)
          {
              prev->next=temp;
              return list1;
          }
      }
    }
    if(curr==NULL)
    {
        prev->next=list2;
       // return list1;
    }
    return list1;
}
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
    {
        return list2;
    }
    if(list2==NULL)
    {
        return list1;
    }
    if(list1->val<list2->val)
    {
        return solve(list1,list2);
    }
    else
    {
        return solve(list2,list1);
    }
    return list1;
    }
};