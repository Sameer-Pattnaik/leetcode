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
int sum(vector<int>&arr)
{
    int n=arr.size();
    int i=0;
    int j=n-1;
    int maxSum=INT_MIN;
    while(i<=j)
    {
        int sol=arr[i]+arr[j];
        maxSum=max(maxSum,sol);
        i++;
        j--;
    }
    return maxSum;
}
    int pairSum(ListNode* head) {
        vector<int>arr;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int add=sum(arr);
        return add;
    }
};