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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        ListNode* temp1 = head;
        int count = 0;
        
        // Count the number of nodes in the list
        while (temp1 != NULL) {
            temp1 = temp1->next;
            count++;
        }

        // If k is greater than the number of nodes, no reversal is needed
        if (k > count) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = nullptr;

        // Main loop to reverse k-group nodes
        ListNode* newHead = nullptr; // To track the new head after the first group is reversed
        ListNode* prevTail = nullptr; // To connect previous groups with the current group

        while (count >= k) {
            // Move the fast pointer k steps ahead
            for (int i = 1; i < k; ++i) {
                fast = fast->next;
            }
            
            temp = fast->next;

            // Reverse the current k-group
            ListNode* prev = nullptr;
            ListNode* curr = slow;
            ListNode* next = nullptr;

            while (curr != temp) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Update pointers for the first reversed group
            if (newHead == nullptr) {
                newHead = fast;
            }

            // Connect the previous group's tail to the current group's head
            if (prevTail != nullptr) {
                prevTail->next = fast;
            }

            prevTail = slow;
            slow = temp;
            fast = temp;
            count -= k;
        }

        // Connect the remaining nodes (if any) to the last group's tail
        if (prevTail != nullptr) {
            prevTail->next = slow;
        }

        return newHead == nullptr ? head : newHead;
    }
};
