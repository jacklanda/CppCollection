#include <stdio.h>
#include <stdlib.h>

#define ARRAY_NUM 6
#define SUCCESS "查找到了噢"
#define FAILED "未查找到噢"

typedef struct SinglyLinkedList {
    int item;
    struct SinglyLinkedList* next;
} * PNode, Node;

PNode create_list(int arr[]);
PNode create_node(int val);
PNode search_list(PNode List, int target);
void delete_list(PNode node);

int main() {
    int arr[ARRAY_NUM] = {45, 22, 1, 18, 996, 1024};
    PNode SLList = create_list(arr);
    PNode result = search_list(SLList, 133);
    if (result == NULL) {
        printf("找不到噢");
    } else {
        printf("成功找到了%d", result->item);
    }
    return 0;
}

PNode create_list(int arr[]) {
    PNode head = create_node(arr[0]);
    PNode list = head;
    PNode node;
    for (int i = 1; i < ARRAY_NUM; i++) {
        node = create_node(arr[i]);
        head->next = node;
        head = head->next;
    }
    return list;
}

PNode create_node(int val) {
    PNode node = (PNode)malloc(sizeof(Node));
    node->item = val;
    node->next = NULL;
    return node;
}

PNode search_list(PNode List, int target) {
    PNode curr_node = List;
    if (curr_node == NULL) return NULL;
    if (curr_node->item == target) {
        return curr_node;
    } else {
        return search_list(curr_node->next, target);
    }
}

void delete_list(PNode node) {}
