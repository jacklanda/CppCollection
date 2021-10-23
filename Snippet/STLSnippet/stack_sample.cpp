#include <iostream>
#include <stack>

using std::cout;
using std::stack;

int main(int argc, char** argv) {
    /* Special member function */
    stack<int> stk;  // default ctor
    stack<int> stk_tmp(stk);  // copy ctor, equivalent to `stk<int> stk_tmp = stk`;
    stk = stk_tmp;  // copy assignment operator

    /* Modifier method */
    stk.push(1);
    stk.push(2);
    stk.emplace(3);  // emplace is more efficiently!
    stk.pop();
    stk.swap(stk_tmp);  // swap contents with other queue object
    stk.swap(stk_tmp);

    /* Capacity method */
    if (!stk.empty()) {
        cout << "Stack is not empty!\n";
        cout << "Its size is: " << stk.size() << '\n';
    }

    /* Element access method */
    {
        int val_top = stk.top();
        cout << "The value at front of Queue is: " << val_top << '\n';
    }
}
