/* 辅助单调栈 & 后序遍历的镜像 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        std::stack<int> stk;
        int root = INT_MAX;
        for (int i = postorder.size() - 1; i >= 0; --i) {
            if (postorder[i] > root) return false;
            while (!stk.empty() && stk.top() > postorder[i]) {
                root = stk.top();
                stk.pop();
            }
            stk.push(postorder[i]);
        }
        return true;
    }
};
