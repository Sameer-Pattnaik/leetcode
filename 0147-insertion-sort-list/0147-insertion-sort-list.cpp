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
void insertionSort(vector<int>&ans)
{
    for(int i=1;i<ans.size();i++)
    {
        int current=ans[i];
        int j=i-1;
        for(;j>=0;j--)
        {
        if(ans[j]>current)
        {
            ans[j+1]=ans[j];
            
        }
        else
        {
            break;
        }
        
        }
        ans[j+1]=current;
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode*ansHead=NULL;
        ListNode*ansTail=NULL;
        ListNode*temp=head;
        vector<int>ans;
        while(temp!=NULL)
        {
            ans.push_back(temp->val);
            temp=temp->next;
        }
        insertionSort(ans);
        for(int i=0;i<ans.size();i++)
        {
            insertAtTail(ansHead,ansTail,ans[i]);
        }
        return ansHead;
    }
};