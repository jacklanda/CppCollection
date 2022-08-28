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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/* time complexity: O(n) */
/* space complexity: O(log(n)) */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return build_tree(head, nullptr);
    }
private:
    TreeNode* build_tree(ListNode* head, ListNode* tail) {
        if (head == tail) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail and fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = build_tree(head, slow);
        root->right = build_tree(slow->next, tail);
        return root;
    }
};
