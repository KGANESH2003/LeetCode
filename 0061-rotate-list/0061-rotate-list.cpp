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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL||head->next==NULL||k==0)
        {
            return head;
        }
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        k=k%count;
        if(k==0)
        {
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(k--)
        {
            fast=fast->next;
        }
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        prev=slow->next;
        slow->next=NULL;
        fast->next=head;
        return prev;
    }
};