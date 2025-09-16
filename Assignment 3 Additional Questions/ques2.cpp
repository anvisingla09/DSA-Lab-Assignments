#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<long long> st;
    long long mini;

public:
    void push(int x) {
        if (st.empty()) {
            st.push(x);
            mini = x;
        } else {
            if (x < mini) {
                st.push(2LL * x - mini); 
                mini = x;
            } else {
                st.push(x);
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long t = st.top();
        st.pop();
        if (t < mini) {
            mini = 2LL * mini - t; 
        }
    }

    int top() {
        if (st.empty()) return -1;
        long long t = st.top();
        return (t < mini) ? mini : t;
    }

    int getMin() {
        return mini;
    }

    bool empty() {
        return st.empty();
    }
};

int main() {
    SpecialStack s;
    s.push(3);
    s.push(5);
    cout << s.getMin() << endl; 
    s.push(2);
    s.push(1);
    cout << s.getMin() << endl; 
    s.pop();
    cout << s.getMin() << endl; 
}

