/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/* BFS */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;
        
        queue<Node*> q;
        q.emplace(root);
        q.emplace(nullptr);
        while (q.size() > 1) {
            Node* node = q.front();
            q.pop();
            if (node == nullptr) {
                q.emplace(nullptr);
                continue;
            }
            node->next = q.front();
            if (node->left) q.emplace(node->left);
            if (node->right) q.emplace(node->right);
        }
        
        return root;
    }
};
