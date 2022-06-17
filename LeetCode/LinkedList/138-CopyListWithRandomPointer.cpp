/* time complexity: O(n) */
/* space complexity: O(n) */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        std::unordered_map<Node*, Node*> node2node;
        Node* curr = head;
        while (curr) {
            node2node[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr) {
            node2node[curr]->next = node2node[curr->next];
            node2node[curr]->random = node2node[curr->random];
            curr = curr->next;
        }
        return node2node[head];
    }
};
