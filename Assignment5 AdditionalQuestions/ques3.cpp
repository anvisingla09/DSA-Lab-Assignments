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
public:
Node* head;
Node* tail;
List(){
  head=tail=NULL;
}

void push_front(int val){
  Node* newNode = new Node(val);
  if(head==NULL){
    head=tail=newNode;
  }
  else{
    newNode->next = head;
    head = newNode;
  }
}

void printList(){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
}

bool detectCycle(Node* head){
  Node* slow = head;
  Node* fast = head;
  while(fast!=NULL && fast->next!=NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow==fast) return true;
  }
  return false;
}
};
int main(){
  List ll;
  ll.push_front(5);
  ll.push_front(4);
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);
  ll.printList();
  ll.tail->next = ll.head->next->next;
  if(ll.detectCycle(ll.head)){
    cout<<"cycle is detected."<<endl;
  } 
  else{
    cout<<"cycle not detected."<<endl;
  }
}
