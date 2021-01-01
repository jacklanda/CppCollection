/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode preNode;
    struct ListNode* pre = &preNode;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            pre->next = l1;
            l1 = l1->next;
        } else {
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    if (l1)
        pre->next = l1;
    else
        pre->next = l2;
    return preNode.next;
}
