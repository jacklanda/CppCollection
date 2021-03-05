class MyQueue {
private:
    stack<int> in_stack, out_stack;
    void in2out() {
        while (!in_stack.empty()) {
            out_stack.push(in_stack.top());
            in_stack.pop();
        }
    }

public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { in_stack.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (out_stack.empty()) in2out();
        int element = out_stack.top();
        out_stack.pop();
        return element;
    }

    /** Get the front element. */
    int peek() {
        if (out_stack.empty()) in2out();
        return out_stack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return (in_stack.empty() && out_stack.empty()) ? true : false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
