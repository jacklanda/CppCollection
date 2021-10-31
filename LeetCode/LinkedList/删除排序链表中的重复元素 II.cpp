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

/* 三指针 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* dh = new ListNode(INT_MAX, head);
        ListNode* slow = dh;
        ListNode* midd = dh->next;
        ListNode* fast = dh->next->next;
        while (fast) {
            if (midd->val == fast->val) {
                while (fast && midd->val == fast->val) fast = fast->next;
                slow->next = fast;
                midd = fast;
                if (fast)
                    fast = fast->next;
                else
                    break;
            } else {
                slow = slow->next;
                midd = midd->next;
                fast = fast->next;
            }
        }
        return dh->next;
    }
};
