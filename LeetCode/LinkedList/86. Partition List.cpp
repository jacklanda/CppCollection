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

/* time complexity: O(n) */
/* space complexity: O(1) */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode lt;
        ListNode ge;
        ListNode* p1 = &lt;
        ListNode* p2 = &ge;
        while (head != nullptr) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p1->next = ge.next;
        p2->next = nullptr;

        return lt.next;
    }
};
