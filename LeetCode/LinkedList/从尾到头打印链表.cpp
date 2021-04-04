/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 以函数栈帧来模拟压栈 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> vec;
        reverse(head, vec);
        return vec;
    }
    void reverse(ListNode* head, vector<int>& vec) {
        if (!head) return;
        reverse(head->next, vec);
        vec.push_back(head->val);
        return;
    }
};
