#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}Node, *PNode;

void createTwoLists(PNode l1, PNode l2);
PNode newNode(PNode now, int val);
void display(PNode list);
PNode mergeTwoLists(PNode l1, PNode l2);

int main(){
    PNode l1, l2;
    createTwoLists(l1, l2);
    display(l1);
    /* mergeTwoLists(l1, l2); */

    return 0;
}

void createTwoLists(PNode l1, PNode l2){
    PNode list1 = l1;
    PNode list2 = l2;

    list1 = newNode(list1, 22);
    list1 = newNode(list1, 333);
    list1 = newNode(list1, 798);

    list2 = newNode(list2, 99);
    list2 = newNode(list2, 10036);
    list2 = newNode(list2, 7);
    return;
}

PNode newNode(PNode now, int val){
    PNode node = (PNode)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    now->next = node;
    return node;
}

void display(PNode list){
    PNode node = list;
    for(int i=0; i<3; i++){
        printf("[%d] ", node->val);
        node = node->next;
    }
    return;
}


