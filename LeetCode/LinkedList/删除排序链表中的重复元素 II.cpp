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

/* Three-pointers approach */
/* time complexity: O(n) */
/* space complexity: O(1) */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode dummy(INT_MAX, head);
        ListNode* prev = &dummy;
        ListNode* curr = dummy.next;
        ListNode* next = curr->next;
        while (next) {
            if (next->val == curr->val) {
                while (next && curr->val == next->val)
                    next = next->next;
                prev->next = next;
                curr = next;
                next = next != nullptr ? next->next : next;
            } else {
                prev = prev->next;
                curr = curr->next;
                next = next->next;
            }
        }
        return dummy.next;
    }
};
