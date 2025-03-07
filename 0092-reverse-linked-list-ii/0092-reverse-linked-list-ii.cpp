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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==NULL||head->next==NULL||left==right)
        {
            return head;
        }

        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp1=NULL;
        ListNode* temp2=NULL;

        for(int i=1;i<left;++i)
        {
            temp1=slow;
            slow=slow->next;
        }

        for(int i=1;i<=right;++i)
        {
            fast=fast->next;
        }

        temp2=fast;
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* next = nullptr;
        while(curr!=temp2)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        if(temp1!=NULL)
        {
            temp1->next=prev;
        }else{
            head=prev;
        }

        slow->next=temp2;
        return head;

    }
};