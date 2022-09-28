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
    
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(!head or !head->next)
            return NULL;
        ListNode* fast=head,*slow=head;
        while(n--)
        {
            fast=fast->next;
        }
        if(fast==NULL)  //Means n==size of linked list, i.e we are to delete the first node
            return head->next;
        while(fast->next)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};