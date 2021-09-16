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

/* 递归法: */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n); */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
};

/* 迭代法 */
/* 时间复杂度: O(n), n为链表长度 */
/* 空间复杂度: O(1) */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dmy = new ListNode(0);  // 定义一个虚拟头结点
        ListNode* cur = dmy;

        if (!l1)
            return l2;
        else if (!l2)
            return l1;
        else if (!l1 && !l2)
            return nullptr;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else if (l2->val < l1->val) {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;

        return dmy->next;
    }
};
