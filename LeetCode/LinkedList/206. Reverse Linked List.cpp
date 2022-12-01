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
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) => 递归调用的栈空间大小 */
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
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* midd = head->next;
        ListNode* fast = head->next->next;
        slow->next = nullptr;
        while (fast != nullptr) {
            midd->next = slow;
            slow = midd;
            midd = fast;
            fast = fast->next;
        }
        midd->next = slow;

        return midd;
    }
};
