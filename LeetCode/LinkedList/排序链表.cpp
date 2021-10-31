/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/* 解法一： */
/* 使用辅助vector，非原地排序 */
/* 时间复杂度: O(nlogn) */
/* 空间复杂度: O(n) */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* phead = head;
        vector<int> vec;
        while (phead) {
            vec.emplace_back(phead->val);
            phead = phead->next;
        }
        std::sort(vec.begin(), vec.end());
        ListNode* dh = new ListNode();
        ListNode* cur = dh;
        for (const int& n : vec) {
            ListNode* node = new ListNode(n, nullptr);
            cur->next = node;
            cur = cur->next;
        }
        return dh->next;
    }
};

/* 解法二：
 * 两次遍历，
 * 使用STL内置的基于
 * 堆排序的优先级队列 */
/* 时间复杂度: O(nlogn) */
/* 空间复杂度: O(logn) */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        priority_queue<int, vector<int>, greater<int>> pq;
        ListNode* ptr = head;
        while (ptr) {
            pq.push(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            ptr->val = pq.top();
            pq.pop();
            ptr = ptr->next;
        }
        return head;
    }
};

/* 解法二：
 * 归并排序（递归式->自顶向下）
 * 时空复杂度：O(nlogn), O(logn)
 * */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next) {
            //记录slow的前驱，针对链表有偶数个结点的情况
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        //明确递归函数的返回结果是什么，sortList的返回结果就是已经排序好的链表的头节点；而merge的返回结果就是两个链表合并好之后的链表的头节点
        return merge(sortList(head), sortList(slow));
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val <= l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};

