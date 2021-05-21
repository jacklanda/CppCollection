class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(): val(0), next(nullptr) {}
        ListNode(int x): val(x), next(nullptr) {}
        ListNode(int x, ListNode* next): val(x), next(next) {}
    };
    /** Initialize your data structure here. */
    MyLinkedList() {
        dummy_head = new ListNode(0);
        list_size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index > list_size - 1 || index < 0) return -1;
        ListNode* curr = dummy_head->next;
        while(index--) curr = curr->next;
        return curr->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* node = new ListNode(val, dummy_head->next);
        dummy_head->next = node;
        list_size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* curr = dummy_head;
        ListNode* node = new ListNode(val);
        while(curr->next) curr = curr->next;
        curr->next = node;
        list_size++;
    }

    /** Add a node of value val before the index-th node in the linked list.
    If index equals to the length of linked list, the node will be appended to the end of linked list.
    If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > list_size) return;
        ListNode* node = new ListNode(val);
        ListNode* curr = dummy_head;
        while(index--) curr = curr->next;
        node->next = curr->next;
        curr->next = node;
        list_size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= list_size) return;
        ListNode* curr = dummy_head;
        while(index--) curr = curr->next;
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp; temp = nullptr;
        list_size--;
    }
private:
    int list_size;
    ListNode* dummy_head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
