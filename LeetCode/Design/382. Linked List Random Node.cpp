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

/* Reservoir sampling */
/* time complexity: O(n) */
/* space complexity: O(1) */
class Solution {
public:
    Solution(ListNode* head) : head(head) {}

    int getRandom() {
        int ans = 0, i = 1;
        ListNode* curr = head;
        while (curr) {
            if (std::rand() % i == 0) ans = curr->val;
            ++i;
            curr = curr->next;
        }
        return ans;
    }
private:
    ListNode* head;
};

/* Brute Force */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    Solution(ListNode* head) {
        ListNode* curr = head;
        while (curr) {
            vals.emplace_back(curr->val);
            curr = curr->next;
        }
    }
    
    int getRandom() {
        return vals[std::rand() % vals.size()];
    }
private:
    std::vector<int> vals;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
