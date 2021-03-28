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
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* l2_begin = list2;
        ListNode* l2_end = list2;
        while (l2_end->next) l2_end = l2_end->next;

        int before_a = 1;
        ListNode* it = list1;
        ListNode* l1_before_a;
        ListNode* l1_after_b;
        while (before_a <= b) {
            if (before_a == a) l1_before_a = it;
            it = it->next;
            before_a++;
        }
        l1_after_b = it->next;
        l1_before_a->next = l2_begin;
        l2_end->next = l1_after_b;
        return list1;
    }
};
