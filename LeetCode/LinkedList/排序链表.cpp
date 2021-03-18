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

/* 两次遍历，
 * 使用STL内置的基于
 * 堆排序的优先级队列 */
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
