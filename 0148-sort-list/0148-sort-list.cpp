class Solution {
public:
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;  // Fast starts ahead to split correctly

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left) return right;
        if (!right) return left;

        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        while (left && right) {
            if (left->val < right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        temp->next = left ? left : right;
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Find mid and split list
        ListNode* mid = findMid(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr;

        // Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        // Merge sorted halves
        return merge(left, right);
    }
};
