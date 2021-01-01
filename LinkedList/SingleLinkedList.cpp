typedef struct MyLinkedList {
    int val;
    struct MyLinkedList* next;
} * PNode, Node, MyLinkedList;

MyLinkedList* myLinkedListCreate();
int myLinkedListGet(PNode obj, int index);
void myLinkedListAddAtHead(PNode obj, int val);
void myLinkedListAddAtTail(PNode obj, int val);
void myLinkedListAddAtIndex(PNode obj, int index, int val);
void myLinkedListDeleteAtIndex(PNode obj, int index);
void myLinkedListFree(PNode obj);

MyLinkedList* myLinkedListCreate() {
    PNode node = (PNode)malloc(sizeof(Node));
    node->val = 0;
    node->next = NULL;
    return node;
}

int myLinkedListGet(PNode obj, int index) {
    int length = 0;
    PNode node = obj;
    while (node != NULL) {
        node = node->next;
        length += 1;
    }
    if (index < 0 || index > length) {
        return -1;
    } else {
        int count = 0;
        int val;
        PNode curr_node = obj;
        while (count != index) {
            curr_node = curr_node->next;
            count += 1;
        }
        val = curr_node->next->val;
        return val;
    }
    return -1;
}

void myLinkedListAddAtHead(PNode obj, int val) {
    PNode node = (PNode)malloc(sizeof(Node));
    if (node == NULL) printf("malloc failed!") node->val = val;
    node->next = obj->next;
    obj->next = node;
    return;
}

void myLinkedListAddAtTail(PNode obj, int val) {
    PNode node = (PNode)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    PNode curr_ptr = obj;
    while (curr_ptr->next != NULL) {
        curr_ptr = curr_ptr->next;
    }
    curr_ptr->next = node;
    return;
}

void myLinkedListAddAtIndex(PNode obj, int index, int val) {
    int length = 0;
    PNode node = obj;
    while (node != NULL) {
        node = node->next;
        length += 1;
    }
    PNode head_node = obj;
    PNode curr_node = obj;
    PNode new_node = (PNode)malloc(sizeof(Node));
    new_node->val = val;
    if (index < 0) {
        new_node->next = head_node->next;
        head_node->next = new_node;
    } else if (index == length) {
        while (curr_node->next != NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    } else if (index > length) {
        return;
    } else {
        int pos = 1;
        while (pos < index) {
            curr_node = curr_node->next;
            pos += 1;
        }
        new_node->next = curr_node->next;
        curr_node->next = new_node;
    }
    return;
}

void myLinkedListDeleteAtIndex(PNode obj, int index) {
    int length = 0;
    PNode node = obj;
    while (node != NULL) {
        node = node->next;
        length += 1;
    }
    PNode curr_node = obj;
    if (0 <= index && index <= length) {
        int count = 0;
        while (count != index) {
            curr_node = curr_node->next;
            count += 1;
        }
        free(curr_node->next);
        curr_node->next = NULL;
    }
    return;
}

void myLinkedListFree(PNode obj) {
    PNode curr_node = obj;
    while (curr_node->next != NULL) {
        PNode post_node = curr_node;
        curr_node = curr_node->next;
        free(post_node);
        post_node = NULL;
    }
    free(curr_node);
    curr_node = NULL;
    return;
}

