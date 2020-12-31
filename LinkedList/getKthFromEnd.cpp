/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* solution 1 - slow but easy to understand:
 * Firstly, traverse and get the length of list, according to the length, it's easy to get    the Kth node with the elements behide it while traversing again through the serial path.
 */

struct ListNode* getKthFromEnd(struct ListNode* head, int k){
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
