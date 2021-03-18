/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 1.
 * 使用一对快慢指针，先判断链表是否有环，如果无环则返回nullptr，有环则进入下一步；
 * 2. 让慢指针重新指向链表的头结点，然后再让快指针和慢指针
 *    一步一步地同步前进，最终两指针相遇处即为链表环的入口处。
 * */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};
