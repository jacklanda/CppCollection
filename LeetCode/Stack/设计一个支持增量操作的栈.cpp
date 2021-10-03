class CustomStack {
public:
    CustomStack(int maxSize) : max_size(maxSize) {}

    void push(int x) {
        if (stk.size() >= max_size) return;
        stk.push_back(x);
    }

    int pop() {
        if (stk.empty()) return -1;
        int tmp{stk.back()};
        stk.pop_back();
        return tmp;
    }

    void increment(int k, int val) {
        if (stk.size() <= k) {
            for (auto& n : stk) n += val;
        } else if (stk.size() > k) {
            for (int i = 0; i < k; ++i) stk[i] += val;
        }
    }

private:
    int max_size;
    std::vector<int> stk;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
