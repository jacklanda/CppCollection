/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 通过栈容器的压/弹栈实现 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> stk;
        vector<int> vec;
        while (head) {
            stk.push(head->val);
            head = head->next;
        }
        while (!stk.empty()) {
            vec.push_back(stk.top());
            stk.pop();
        }
        return vec;
    }
};

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

