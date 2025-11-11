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
class List{
Node* head;
Node* tail;
public:
List(){
  head = tail = NULL;
}

void push_front(int val){
  Node* newNode = new Node(val);
  if(head==NULL){
    head = tail = newNode;
    return ;
  }
  else{
    newNode->next = head;
    head = newNode;
  }
}

Node* reverseList(){
  Node* prev = NULL;
  Node* curr = head;
  Node* next = NULL;
  while(curr!=NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
  return prev;
  
}

void printList(){
  Node* temp = head;
  if(head == NULL){
    cout<<"list is empty\n";
    return;
  }
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
}
};
int main(){
  List ll;
  ll.push_front(6);
  ll.push_front(5);
  ll.push_front(4);
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);
  ll.printList();
  ll.reverseList();
  ll.printList();
  return 0;
}
