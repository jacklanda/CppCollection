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

/** 
 * Classic LinkedList sorting used MergeSort
 * Key points: 
 * 1. MergeSort, 
 * 2. Turtle-hare Algo(Two pointer approach), 
 * 3. Merge Two LinkedLists 
 **/

/* time complexity: O(n*log(n)) */
/* space complexity: O(log(n)) */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        // Turtle-hare Algo (two-pointer approach, to find the middle node)
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            temp = slow;
            slow = slow->next;  // slow increment by 1
            fast = fast->next->next;  // fast increment by 2
        }
        temp->next = nullptr;  // end of left half
        
        ListNode* left = sortList(head);  // left half recursive call
        ListNode* right = sortList(slow);  // right half recursive call
        
        return merge(left, right);  // merge two linked lists
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* cur = &dummy;
        
        while (l1 && l2) {
            if (l1->val > l2->val) {
                cur->next = l2;
                l2 = l2->next;
            } else {
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        else if (l2) cur->next = l2;
        
        return dummy.next;
    }
};
