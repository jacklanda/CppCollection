struct ListNode {
    int val;
    struct ListNode* next;
};

/* 方法一：递归交换结点对 */
struct ListNode* swapPairs(struct ListNode* head){
    /* 边界条件 */
    if(head == NULL || head->next == NULL){
        return head;
    }
    /* 在断链前，先记录下第二个结点 */
    struct ListNode* newHead = head->next;
    /* 递归地交换结点 */
    head->next = swapPairs(newHead->next);
    /* 让第二结点指向第一结点 */
    newHead->next = head;

    return newHead;
}

/* 方法二：利用伪头结点，使用三指针进行统一化操作 */
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode forged;
    forged->next = head;
    struct ListNode* pForged = forged;
    struct ListNode* first = head;
    struct ListNode* second = head->next;
    if()
}
