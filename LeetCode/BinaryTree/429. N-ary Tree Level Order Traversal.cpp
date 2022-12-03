/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/* BST */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr)
            return {};
        
        vector<vector<int>> vec;
        queue<Node*> q;
        q.emplace(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> sub_vec;
            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();
                sub_vec.emplace_back(node->val);
                for (Node* n : node->children)
                    if (n != nullptr) 
                        q.emplace(n);
            }
            vec.emplace_back(sub_vec);
        }
        
        return vec;
    }
};
