/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* 双指针-前后指针 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;
        else if (head->val == val)
            return head->next;

        ListNode* post = head;
        ListNode* prev = head->next;
        while (prev) {
            if (prev->val == val) {
                post->next = prev->next;
                break;
            } else {
                prev = prev->next;
                post = post->next;
            }
        }
        return head;
    }
};
