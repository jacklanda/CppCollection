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

/* 双指针一次遍历即可 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast) {
            if (fast->val == slow->val) {
                ListNode* temp = fast;
                fast = fast->next;
                slow->next = fast;
                delete (temp);
            } else {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return head;
    }
};
