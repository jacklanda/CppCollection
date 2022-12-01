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

/* Recursive approach */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* new_head = head->next;
        head->next = swapPairs(new_head->next);
        new_head->next = head;
        return new_head;
    }
};

/* Non-recursive approach */
/* time complexity: O(n) */
/* space complexity: O(1) */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy = ListNode(0, head);
        ListNode* prev = &dummy;
        while (prev->next && prev->next->next) {
            ListNode* n1 = prev->next;
            ListNode* n2 = prev->next->next;
            n1->next = n2->next;
            n2->next = n1;
            prev->next = n2;
            prev = n1;
        }

        return dummy.next;
    }
};
