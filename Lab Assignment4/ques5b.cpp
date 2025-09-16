#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for (int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Empty\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) cout << "Stack Empty\n";
        else cout << "Top: " << q.front() << endl;
    }
};

int main() {
    Stack st;
    st.push(5);
    st.push(15);
    st.push(25);
    st.top();
    st.pop();
    st.top();
    return 0;
}
