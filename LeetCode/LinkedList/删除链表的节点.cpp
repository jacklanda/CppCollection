/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* 注意初始边界条件检查 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;
        else if (head->val == val)
            return head->next;
        ListNode* cur = head;
        while (cur->next) {
            if (cur->next->val == val && cur->next->next != nullptr) {
                cur->next = cur->next->next;
                break;
            } else if (cur->next->val == val && cur->next->next == nullptr) {
                cur->next = nullptr;
                break;
            }
            cur = cur->next;
        }
        return head;
    }
};
