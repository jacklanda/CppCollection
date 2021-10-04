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

/* 利用优先级队列自定义堆排序规则 */
/* 时间复杂度: O(kn*logk) */
/* 空间复杂度: O(k) */
class Comp {
public:
    constexpr bool operator()(ListNode* n1, ListNode* n2) {
        return n1->val > n2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, Comp> pq;
        for (ListNode* n : lists) {
            if (n) pq.push(n);
        }
        ListNode *dummy = new ListNode(), *cur = dummy;
        while (!pq.empty()) {
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
            if (cur->next) {
                pq.push(cur->next);
            }
        }
        return dummy->next;
    }
};
