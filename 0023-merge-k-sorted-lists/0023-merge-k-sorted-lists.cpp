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
    ListNode* mergeLists(ListNode* l1,ListNode* l2)
    {
        if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        if(l1->val<=l2->val)
        {
            l1->next=mergeLists(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=mergeLists(l1,l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode* mergeTwoLists(int s,int e,vector<ListNode*>&lists)
    {
        if(s>e)
        {
            return NULL;
        }
        if(s==e)
        {
            return lists[s];
        }
        int mid=(s+e)/2;
        ListNode* l1=mergeTwoLists(s,mid,lists);
        ListNode* l2=mergeTwoLists(mid+1,e,lists);
        return mergeLists(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0)
        {
            return NULL;
        }
        return mergeTwoLists(0,k-1,lists);
    }
};