/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    if(node->next->next){
        node->val = node->next->val;
        deleteNode(node->next);
    }else{
        node->val = node->next->val;
        node->next = NULL;
    }
    return;
}
