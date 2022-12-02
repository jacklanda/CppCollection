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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // leverage checker to check whether
        // the current group of nodes need to reverse
        // for the last group, it will return directly 
        // without the later reverse operations.
        ListNode* checker = head;
        for (int i = 0; i < k; ++i) {
            if (checker == nullptr)
                return head;
            checker = checker->next;
        }
        
        // Classic Linkedlist reverse impl
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i = 0; i < k; ++i) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};

/* None-recursive approach */
/* time complexity: O(n) */
/* space complexity: O(1) */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* n1 = dummy;  // save the original node before head
        ListNode* n2 = head;  // save the original head;
        ListNode* prev = nullptr;
        ListNode* curr = nullptr;
        ListNode* next = nullptr;
        while (true) {
            ListNode* checker = n2;  // check from the head of new group
            for (int i = 0; i < k; ++i) {
                if (checker == nullptr)
                    return dummy->next;
                checker = checker->next;
            }

            prev = n1;  // reset prev to the node before new head node
            curr = n2;  // reset curr to the new head node
            for (int i = 0; i < k; ++i) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            n2->next = curr;
            n1->next = prev;
            n1 = n2;
            n2 = curr;
        }

        return dummy->next;
    }
};
