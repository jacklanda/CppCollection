#include <stdio.h>
#include <stdlib.h>

typedef struct SinglyLinkedList {
    int val;
    struct SinglyLinkedList* next;
} SinglyLinkedList, *PNode, Node;

int main() {
    PNode node_a = (PNode)malloc(sizeof(SinglyLinkedList));
    PNode node_b = (PNode)malloc(sizeof(short));
    node_a->val = 1;
    node_b->val = 6;
    printf("node_a's val is: [%d], node_b's val is: [%d]\n", node_a->val,
           node_b->val);
    printf("node_a's mem is: [%d]bytes, node_b's mem is: [%d]bytes",
           sizeof(Node), sizeof(PNode));
    return 0;
}
