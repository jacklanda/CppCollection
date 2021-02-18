/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int length = 0;
        struct ListNode* getLengthPtr = head;
        while(getLengthPtr){
            getLengthPtr = getLengthPtr->next;
            length += 1;
        }
        int count = 0;
        int startPos = length - k;
        struct ListNode* node = head;
        for(int i=0; i<startPos; i++){
            node = node->next;
        }
        return node;
    }
};
