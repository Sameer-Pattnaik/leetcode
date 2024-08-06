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
vector<int>rotateList(vector<int>&arr,int k)
{
   int n=arr.size();
    k=k%n;
    vector<int>temp;
    for(int i=0;i<n;i++)
    {
        temp.push_back(arr[((n-k)+i)%n]);
    }
    return temp;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
      {
        return NULL;
      }
      ListNode*temp=head;
      ListNode*ansHead=NULL;
      ListNode*ansTail=NULL;
      vector<int>ans;
      
      while(temp!=NULL)
      {
        ans.push_back(temp->val);
        temp=temp->next;
      }
      vector<int>rotate=rotateList(ans,k);
      for(int i=0;i<rotate.size();i++)
      {
        insertAtTail(ansHead,ansTail,rotate[i]);
      } 
      return ansHead; 
    }
};