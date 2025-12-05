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

void splitList(Node* head, Node** head1, Node** head2) {
    Node* slow = head;
    Node* fast = head;

   
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

  
    if (fast->next->next == head)
        fast = fast->next;

  
    *head1 = head;
    *head2 = slow->next;

    slow->next = *head1;

    fast->next = *head2;
}

void printList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(4);
    head->next->next = new Node(9);
    head->next->next->next = head;

    Node *head1 = NULL, *head2 = NULL;

    splitList(head, &head1, &head2);

    cout << "First half: ";
    printList(head1);

    cout << "Second half: ";
    printList(head2);

    return 0;
}

