#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = tail = NULL;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node* rotateLeft(Node* head, int k) {
        if (!head || k == 0) return head;
        Node* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }
        temp->next = head;
        k = k % length;
        int stepsToNewHead = k;
        Node* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }
        Node* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};

int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    cout << "Original List: ";
    ll.printList();

    int k = 2;
    ll.head = ll.rotateLeft(ll.head, k);

    cout << "After rotating left by " << k << ": ";
    ll.printList();
}
