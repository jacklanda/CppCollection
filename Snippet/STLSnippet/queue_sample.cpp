#include <iostream>
#include <queue>

using std::cout;
using std::queue;

int main(int argc, char** argv) {
    /* Special member function */
    queue<int> q;         // default ctor
    queue<int> q_tmp(q);  // copy ctor, equivalent to `queue<int> q_tmp = q`;
    q = q_tmp;            // copy assign

    /* Modifier method */
    q.push(1);
    q.push(2);
    q.emplace(3);  // emplace is more efficiently!
    q.pop();
    q.swap(q_tmp);  // swap contents with other queue object
    q.swap(q_tmp);

    /* Capacity method */
    if (!q.empty()) {
        cout << "Queue is not empty!\n";
        cout << "Its size is: " << q.size() << '\n';
    }

    /* Element access method */
    {
        int val_front = q.front();
        int val_back = q.back();
        cout << "The value at front of Queue is: " << val_front << '\n';
        cout << "The value at back of Queue is: " << val_back << '\n';
    }
}
