#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool canBeSorted(vector<int> A) {
    vector<int> B;
    stack<int> S;
    int expected = 1;
    int n = A.size();

    for (int x : A) {
        S.push(x);
        while (!S.empty() && S.top() == expected) {
            B.push_back(S.top());
            S.pop();
            expected++;
        }
    }

    return (expected == n + 1); 
}

int main() {
    vector<int> A = {1,2,3};
    cout << (canBeSorted(A) ? "YES" : "NO") << endl;

    vector<int> A2 = {3,1,2};
    cout << (canBeSorted(A2) ? "YES" : "NO") << endl;
}
