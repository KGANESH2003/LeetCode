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
    ListNode* oddEvenList(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* temp = fast;

        while (slow != NULL && slow->next != NULL && fast != NULL && fast->next != NULL) {
            slow->next = slow->next->next;
            slow = slow->next;
            fast->next = fast->next->next;
            fast = fast->next;
        }
        
        slow->next = temp;
        return head;
    }
};
