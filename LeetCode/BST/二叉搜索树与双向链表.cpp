/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
/* 中序遍历+数组存储 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    void InorderTraverse(Node* root) {
        if (root == nullptr) return;
        InorderTraverse(root->left);
        vec.emplace_back(root);
        InorderTraverse(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        InorderTraverse(root);
        if (vec.empty()) return nullptr;
        int len = vec.size();
        Node* head = vec.front();
        for (int l = 0; l < len - 1; ++l) {
            vec[l]->right = vec[l + 1];
            vec[l + 1]->left = vec[l];
        }
        vec[0]->left = vec[len - 1];
        vec[len - 1]->right = vec[0];
        return head;
    }

private:
    vector<Node*> vec;
};
