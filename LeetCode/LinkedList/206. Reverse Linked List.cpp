/* https://leetcode-cn.com/problems/reverse-linked-list/ */

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

/* Solution 1. Recursive approach */
/* time complexity: O(n) */
/* space complexity: O(n) => the size of call stack */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        return reverse(head);
    }
    ListNode* reverse(ListNode* head) {
        if (head->next == nullptr) return head;
        ListNode* last = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};

/* Solution 2. Three-pointers approach */
/* time complexity: O(n) */
/* space complexity: O(1) */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;
        while (curr) {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next != nullptr ? next->next : next;
        }

        return prev;
    }
};
