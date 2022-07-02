/* time complexity: O(n) */
/* space complexity: O(n) */

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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> s1, s2;
        while (l1) {
            s1.emplace(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.emplace(l2->val);
            l2 = l2->next;
        }

        ListNode* head = nullptr;
        bool is_carry = false;
        while (!s1.empty() or !s2.empty() or is_carry) {
            int sum = is_carry ? 1 : 0;
            ListNode* node = new ListNode(0, head);
            head = node;

            if (!s1.empty() and !s2.empty()) {
                sum += s1.top() + s2.top();
                s1.pop();
                s2.pop();
            } else if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            } else if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            node->val = sum >= 10 ? sum - 10 : sum;
            is_carry = sum >= 10 ? true : false;
        }

        return head;
    }
};
