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

/* time complexity: O(kn*log(k)) */
/* space complexity: O(n) */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> pq;
        for (ListNode* node : lists) {
            if (node) pq.emplace(node);
        }
        
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (pq.size()) {
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
            if (cur->next) pq.emplace(cur->next);
        }
        
        return dummy->next;
    }
private:
    struct Compare {
        bool operator()(ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        }
    };
};
