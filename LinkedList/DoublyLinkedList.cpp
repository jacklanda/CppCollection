#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct DoubleLinkedList {
    ElementType data;
    DoubleLinkedList* pre;
    DoubleLinkedList* next;
} Node, *PNode;

PNode create_DLList(int* array, int length, PNode list_head, PNode list_rear);
PNode insert_node(PNode new_node, PNode node, int val);
void traversal(PNode head, int length);
void reverse_traversal(PNode rear);

int main() {
    PNode list_head = (PNode)malloc(sizeof(Node));
    PNode list_rear = (PNode)malloc(sizeof(Node));
    list_head->data = 0;
    list_head->pre = NULL;
    list_head->next = NULL;
    int num;
    printf("Please input the num of array: ");
    scanf("%d", &num);
    int* array = (int*)malloc(num * sizeof(int));
    printf("Please input the elements in array below: \n");
    for (int i = 0; i < num; i++) {
        int val = 0;
        scanf("%d", &val);
        *(array + i) = val;
    }
    list_rear = create_DLList(array, num, list_head, list_rear);
    traversal(list_head, num);
    reverse_traversal(list_rear);

    free(list_head);
    list_head = NULL;

    return 0;
}

PNode create_DLList(int* array, int length, PNode list_head, PNode list_rear) {
    PNode node = list_head;
    for (int i = 0; i < length; i++) {
        PNode new_node = (PNode)malloc(sizeof(Node));
        node = insert_node(new_node, node, *(array + i));
    }
    list_rear = node;
    return list_rear;
}

PNode insert_node(PNode new_node, PNode node, int val) {
    new_node->data = val;
    new_node->pre = node;
    new_node->next = NULL;
    node->next = new_node;
    return new_node;
}

void traversal(PNode head, int length) {
    PNode node = head->next;
    printf("the traversal result: ");
    for (int i = 0; i < length + 1; i++) {
        if (node != NULL) {
            printf("[%d] ", node->data);
            node = node->next;
        }
    }
    printf("\n");
    return;
}

void reverse_traversal(PNode rear) {
    PNode node = rear;
    printf("the reverse traversal result: ");
    while (node->pre) {
        printf("[%d] ", node->data);
        node = node->pre;
    }
    return;
}
