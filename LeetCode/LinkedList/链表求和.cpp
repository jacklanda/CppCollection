/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 处理好每次相加后可能产生的进位即可 */
/* 时间复杂度: O(m+n) => m 和 n 分别是链表l1和l2的节点个数 */
/* 空间复杂度: O(max(m, n)) */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* cur = head;
        int carry{0};
        while (l1 || l2 || carry) {
            int sum{carry};
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            int new_val = sum % 10;
            cur->next = new ListNode(new_val);
            cur = cur->next;
        }
        return head->next;
    }
};
