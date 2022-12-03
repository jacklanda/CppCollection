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
        while (!q.empty()) {
            int size = q.size();
            Node* curr = nullptr;
            Node* next = nullptr;
            for (int i = 0; i < size; ++i) {
                Node* curr = q.front();
                q.pop();
                if (!q.empty() && i + 1 < size) {
                    next = q.front();
                    curr->next = next;
                }
                if (curr->left != nullptr) q.emplace(curr->left);
                if (curr->right != nullptr) q.emplace(curr->right);
            }
            if (curr != nullptr) curr->next = nullptr;
        }
        
        return root;
    }
};

/* DFS */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;
        Node* l = root->left;
        Node* r = root->right;
        Node* n = root->next;
        if (l) {
            l->next = r;
            if (n != nullptr) r->next = n->left;
            connect(l);
            connect(r);
        }
        return root;
    }
};
