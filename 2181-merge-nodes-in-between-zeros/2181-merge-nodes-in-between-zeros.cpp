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
void insertAtTail(ListNode* &head,ListNode* &tail,int e)
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
    ListNode* mergeNodes(ListNode* head) {
        vector<int>ans;
        ListNode*temp=head->next;
        int sum=0;
        while(temp!=NULL)
        {
            sum+=temp->val;
            if(temp->val==0)
            {
                ans.push_back(sum);
                sum=0;
            }
            temp=temp->next;
        }
        ListNode*ansHead=NULL;
        ListNode*ansTail=NULL;
        for(int i=0;i<ans.size();i++)
        {
            insertAtTail(ansHead,ansTail,ans[i]);
        }
        return ansHead;
    }
};