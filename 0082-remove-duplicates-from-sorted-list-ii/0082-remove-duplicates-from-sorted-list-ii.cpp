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
vector<int>countOccurences(vector<int>&ans)
{
    map<int,int>mp;
    vector<int>output;
    for(int i=0;i<ans.size();i++)
    {
        mp[ans[i]]++;
    }
    for(auto it:mp)
    {
        if(it.second==1)
        {
            output.push_back(it.first);
        }
    }
    return output;
}
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int>ans;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            ans.push_back(temp->val);
            temp=temp->next;
        }
        vector<int>result=countOccurences(ans);
        ListNode*ansHead=NULL;
        ListNode*ansTail=NULL;
        for(int i=0;i<result.size();i++)
        {
            insertAtTail(ansHead,ansTail,result[i]);
        }
        return ansHead;

    }
};