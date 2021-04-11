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
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0;
        for (auto p = head; p != nullptr; p = p->next) len += 1;  //确定链表长度
        auto left = head;
        for (int i = 1; i < k; i += 1) left = left->next;  //定位到第k个数
        auto right = head;
        for (int i = 1; i < len - k + 1; i += 1)
            right = right->next;      //定位到倒数第k个数
        swap(left->val, right->val);  //交换值
        return head;
    }
};

