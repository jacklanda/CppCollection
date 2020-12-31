#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
}*PNode, Node;

PNode create_new_node(PNode head, int val);
bool hasCycle_1(struct ListNode *head);
bool hasCycle_2(struct ListNode *head);

int main(){
    PNode head = (PNode)malloc(sizeof(Node));
    PNode node_2 = create_new_node(head, 22);
    PNode node_3 = create_new_node(node_2, 343);
    PNode node_4 = create_new_node(node_3, 1);
    PNode tail = create_new_node(node_4, 454555);
    tail->next = head;
    bool result = hasCycle_1(head);  //1.暴力解法：hasCycle_1(); 2.快慢指针：hasCycle_2()
    if(result == true)
        printf("有环");
    else
        printf("无环");

    return 0;
}

PNode create_new_node(PNode head, int val){
    PNode new_node = (PNode)malloc(sizeof(Node));
    new_node->val = val;
    head->next = new_node;
    return new_node;
}

/* 暴力算法 */
bool hasCycle_1(struct ListNode *head) {
    if(!head->next)
        return false;
    else if(head->next == head)
        return true;
    struct ListNode* curr;
    struct ListNode* move;
    for(curr=head; curr!=NULL; curr=curr->next){
        for(move=curr->next; move!=NULL; move=move->next){
            if(move->next->val == curr->val && move->next == curr){
                return true;
            }
        }
    }
    return false;
}

/* 快慢指针法「龟兔赛跑」 */
bool hasCycle_2(struct ListNode *head) {
    if(!head)
        return false;
    else if(!head->next)
        return false;
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while(slow != fast){
        if(fast == NULL)
            return false;
        else if(!fast->next)
            return false;
        else if(!fast->next->next)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}
