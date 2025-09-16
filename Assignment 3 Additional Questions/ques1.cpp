#include <iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nearestSmallerToLeft(vector<int> &A) {
    vector<int> result;
    stack<int> st;

    for (int i = 0; i < A.size(); i++) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop(); 
        }
        if (st.empty()) result.push_back(-1); 
        else result.push_back(st.top());
        st.push(A[i]);
    }
    return result;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> ans = nearestSmallerToLeft(A);

    for (int x : ans) cout << x << " ";
    return 0;
}

