#include <iostream>
using namespace std;

class Node {
public:
    int coeff;  
    int pow;   
    Node* next;

    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

class Polynomial {
public:
    Node* head;

    Polynomial() {
        head = NULL;
    }

    void insertTerm(int coeff, int pow) {
        Node* newNode = new Node(coeff, pow);
        if (head == NULL)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->coeff << "x^" << temp->pow;
            if (temp->next != NULL)
                cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }
};
Node* addPolynomials(Node* p1, Node* p2) {
    Node* result = NULL;
    Node* tail = NULL;

    while (p1 != NULL && p2 != NULL) {
        Node* temp = NULL;
        if (p1->pow == p2->pow) {
            temp = new Node(p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow) {
            temp = new Node(p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else {
            temp = new Node(p2->coeff, p2->pow);
            p2 = p2->next;
        }
        if (result == NULL) {
            result = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    while (p1 != NULL) {
        tail->next = new Node(p1->coeff, p1->pow);
        p1 = p1->next;
        tail = tail->next;
    }

    while (p2 != NULL) {
        tail->next = new Node(p2->coeff, p2->pow);
        p2 = p2->next;
        tail = tail->next;
    }

    return result;
}

int main() {
    Polynomial p1, p2;

    p1.insertTerm(5, 2);
    p1.insertTerm(4, 1);
    p1.insertTerm(2, 0);
    p2.insertTerm(5, 1);
    p2.insertTerm(5, 0);

    cout << "Polynomial 1: ";
    p1.display();
    cout << "Polynomial 2: ";
    p2.display();

    Node* sum = addPolynomials(p1.head, p2.head);

    cout << "Resultant Polynomial: ";
    while (sum != NULL) {
        cout << sum->coeff << "x^" << sum->pow;
        if (sum->next != NULL)
            cout << " + ";
        sum = sum->next;
    }
    cout << endl;

    return 0;
}
