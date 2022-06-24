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

/* using an assistant vector */
/* time complexity: O(max(m, n)) */
/* space complexity: O(max(m, n)) */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::vector<int> nums;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int sum = 0, res = 0;
        bool is_carry = false;
        while (p1 or p2) {
            sum = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + (is_carry ? 1 : 0);
            p1 = p1 ? p1->next : nullptr;
            p2 = p2 ? p2->next : nullptr;
            res = sum >= 10 ? sum - 10 : sum;
            is_carry = sum >= 10 ? true : false;
            nums.emplace_back(res);
            if (!p1 and !p2 and is_carry) nums.emplace_back(1);
        }
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        for (const int& num : nums) {
            ListNode* node = new ListNode(num);
            curr->next = node;
            curr = curr->next;
        }
        return dummy->next;
    }
};

/* optimal solution */
/* time complexity: O(max(m, n)) */
/* space complexity: O(max(m, n)) */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        bool is_carry = false;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (l1 or l2 or is_carry) {
            sum = (is_carry ? 1 : 0) + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            is_carry = sum >= 10 ? true : false;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummy->next;
    }
};
