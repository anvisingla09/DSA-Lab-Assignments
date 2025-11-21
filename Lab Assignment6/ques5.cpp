#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int val){
    data = val;
    next = NULL;
}
};
class LinkedList{
public:
Node* head;
Node* tail;
LinkedList(){
    head = tail = NULL;   
}

void push_front(int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

void display(){
    Node* temp = head;
    cout<<temp->data<<"->";
    temp = temp->next;
    while(temp!=head){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
  cout<<head->data<<endl;
}

bool check(Node* head){
    if(tail->next == head){
        return true;
    }
    else{
        return false;
    }
}

};
int main(){
    LinkedList ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.display();
    if(ll.check(ll.head)){
        cout<<"yess, this is a circular linked list"<<endl;
    }
    else{
        cout<<"no, it is not a circular linked list"<<endl;
    }
    
}
