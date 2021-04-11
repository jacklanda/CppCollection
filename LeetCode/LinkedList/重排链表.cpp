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
/* 时间复杂度：O(n)
 * 空间复杂度：O(n) */
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head) return;
        reorderList(head, head);
    }
    ListNode *reorderList(ListNode *head, ListNode *tail) {
        // 到达尾节点停止递归
        if (tail->next) head = reorderList(head, tail->next);
        // 到达中间节点处理
        if (head == tail) tail->next = head = nullptr;
        // 左链表遍历完
        if (!head) return nullptr;
        // 链表重排
        auto temp = head->next;
        head->next = tail, tail->next = temp;

        if (tail->next == tail) tail->next = nullptr;
        return tail->next;
    }
};

