class SortedStack {
public:
    SortedStack() {}

    void push(int val) {
        std::stack<int> tmp;
        while (!stk.empty() && stk.top() < val) {
            tmp.push(stk.top());
            stk.pop();
        }
        stk.push(val);
        while (!tmp.empty()) {
            stk.push(tmp.top());
            tmp.pop();
        }
    }

    void pop() {
        if (stk.empty()) return;
        stk.pop();
    }

    int peek() { return stk.empty() ? -1 : stk.top(); }

    bool isEmpty() { return stk.empty(); }

private:
    std::stack<int> stk;
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
