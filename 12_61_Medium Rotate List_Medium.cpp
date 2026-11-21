
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        // Find length and tail
        int n = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            n++;
        }

        // Remove unnecessary rotations
        k = k % n;

        if (k == 0) {
            return head;
        }

        // Make the list circular
        tail->next = head;

        // Find the new tail
        int steps = n - k - 1;
        ListNode* newTail = head;

        for (int i = 0; i < steps; i++) {
            newTail = newTail->next;
        }

        // Find new head and break the circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};
