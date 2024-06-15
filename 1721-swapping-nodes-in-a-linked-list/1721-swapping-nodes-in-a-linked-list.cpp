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
void insertAtTail(ListNode*&head,ListNode* &tail,int e)
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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>ans;
        ListNode*ansHead=NULL;
        ListNode*ansTail=NULL;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            ans.push_back(temp->val);
            temp=temp->next;
        }
    
            
            swap(ans[k-1],ans[ans.size()-k]);
            
        
        for(int i=0;i<ans.size();i++)
        {
            insertAtTail(ansHead,ansTail,ans[i]);
        }
        return ansHead;
    }
};