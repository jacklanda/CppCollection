/* 只用一个存储二元组的栈：
 * 时间复杂度：O(1)
 * 空间复杂度：O(n) */
class MinStack {
private:
    stack<pair<int, int>> stk;

public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int val) {
        if (stk.empty())
            stk.push({val, val});
        else
            stk.push({val, min(val, stk.top().second)});
    }

    void pop() { stk.pop(); }

    int top() { return stk.top().first; }

    int getMin() { return stk.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/* 辅助栈法：
 * 时间复杂度：O(1)
 * 空间复杂度：O(n)
 * */
class MinStack {
private:
    stack<int> stk;
    stack<int> min_stk;

public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int val) {
        if (min_stk.empty()) {
            stk.push(val);
            min_stk.push(val);
        } else {
            stk.push(val);
            min_stk.push(min(min_stk.top(), val));
        }
    }

    void pop() {
        stk.pop();
        min_stk.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return min_stk.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
