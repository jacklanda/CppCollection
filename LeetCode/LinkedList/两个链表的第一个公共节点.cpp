/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* a + x + b == b + x + a   ··· x 为共有链长度 */
/* 时间复杂度: O(m+n)
 *             m, n 分别为两条链表各自的总长度(若相交则包含二者公共部分) */
/* 空间复杂度: O(1) 只用了额外的两个指针 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA || pB) {
            if (pA == pB) return pA;
            if (pA) pA = pA->next;
            if (pB) pB = pB->next;
            if (!pA && !pB)
                return nullptr;
            else if (!pA)
                pA = headB;
            else if (!pB)
                pB = headA;
        }
        return nullptr;
    }
};
