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

/* Swap value in node */
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

/* Swap node */
/* time complexity: O(n^2) */
/* space complexity: O(1) */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr or head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        ListNode* cur = head;

        while (cur) {
            while (pre->next and pre->next->val < cur->val)
                pre = pre->next;
            ListNode* next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = next;
            pre = dummy;
        }

        return dummy->next;
    }
};
