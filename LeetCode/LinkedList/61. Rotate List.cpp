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

/* time complexity: O(n) */
/* space complexity: O(1) */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr or head->next == nullptr)
            return head;
        
        int length = 1;
        ListNode* ptr = head;
        
        while (ptr->next) {
            ptr = ptr->next;
            ++length;
        }
        
        ptr->next = head;
        k %= length;
        k = length - k;
        while (k--) ptr = ptr->next;
        head = ptr->next;
        ptr->next = nullptr;
        
        return head;
    }
};
