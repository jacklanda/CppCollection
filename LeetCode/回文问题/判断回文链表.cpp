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

/* 法一：递归逆序比较法 */
class Solution {
public:
    ListNode* first;
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        first = head;
        return traverse(head->next);
    }

    bool traverse(ListNode* right) {
        if (!right) return true;
        bool res = traverse(right->next);
        res = res && first->val == right->val;
        first = first->next;
        return res;
    }
};
