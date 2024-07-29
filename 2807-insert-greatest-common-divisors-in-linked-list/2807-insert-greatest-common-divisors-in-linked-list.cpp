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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        vector<int>ans;
        if(head->next==NULL)
        {
            return head;
        }
        ListNode*ansHead=NULL;
        ListNode*ansTail=NULL;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            ans.push_back(temp->val);
            temp=temp->next;
        }
        vector<int>result;
        int gcd1=0;
        int gcd2=0;
        result.push_back(ans[0]);
        for(int i=0;i<ans.size();i++)
        {
           if(i==0)
           {
            continue;
           }
           else
           {
             gcd1=ans[i-1];
             gcd2=ans[i];
            
             result.push_back(gcd(gcd1,gcd2));
             result.push_back(ans[i]);
             
           }
        }
        for(int i=0;i<result.size();i++)
        {
            insertAtTail(ansHead,ansTail,result[i]);
        }
        return ansHead;
    }
};