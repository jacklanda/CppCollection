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

/* 迭代遍历 - 快慢双指针 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy_head = new ListNode(0, head);
        ListNode* fast = dummy_head;
        ListNode* slow = dummy_head;
        while (n-- && fast) fast = fast->next;
        fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy_head->next;
    }
};

/* 递归遍历 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        ListNode* dh = new ListNode(0, head);
        recursion(dh, n);
        return dh->next;
    }
    int recursion(ListNode* head, int n) {
        if (head == nullptr) return -1;
        int order = recursion(head->next, n) + 1;
        if (order == n) head->next = head->next->next;
        return order;
    }
};
