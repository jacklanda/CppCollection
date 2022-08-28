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

/* time complexity: O(n^2) */
/* space complexity: O(1) */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
            for (ListNode* comp = head; comp != curr; comp = comp->next) {
                if (comp->val > curr->val) std::swap(comp->val, curr->val);
            }
        }
        return head;
    }
};
