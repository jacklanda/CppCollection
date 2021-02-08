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

/* Solution 1. Recursive method */
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

/* Solution 2. Three-Pointers Method */
class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return head;
        } else if (!head->next) {
            return head;
        } else if (!head->next->next) {
            head->next->next = head;
            ListNode* temp = head->next;
            head->next = nullptr;
            return temp;
        }
        ListNode* prev = head->next->next;
        ListNode* curr = head->next;
        ListNode* post = head;
        post->next = nullptr;
        while (prev) {
            curr->next = post;
            post = curr;
            curr = prev;
            prev = prev->next;
        }
        curr->next = post;

        return curr;
    }
};
