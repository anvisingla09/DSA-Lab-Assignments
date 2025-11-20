// DOUBLY LINKED LIST

#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node* prev;

Node(int val){
  data = val;
  next = NULL;
  prev = NULL; 
}
};
class DoublyList{
Node* head;
Node* tail;
public:
DoublyList(){
head = tail = NULL;
}

void push_front(int val){
  Node* newNode = new Node(val);
  if(head == NULL){
    head = tail = newNode;
  }
  else{
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

void push_back(int val){
  Node* newNode = new Node(val);
  if(head==NULL){
    head = tail = newNode;
  }
  else{
    newNode->prev = tail;
    tail->next = newNode;
    newNode->next = NULL;
    tail = newNode;
  }
}

void pop_front(){
  Node* temp = head;
  head = head->next;
  if(head!=NULL){
    head->prev = NULL;
    temp->next = head;
  }
  delete temp;
}

void pop_back(){
  Node* temp = tail;
  tail = tail->prev;
  if(tail!=NULL){
    tail->next = NULL;
  }
  temp->prev = NULL;
  delete temp;
}

void display(){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<"<=>";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;
}

int size(){
  Node* temp = head;
  int count = 0;
  while(temp!=NULL){
    count++;
    temp = temp->next;
  }
  return count;
}
};
int main(){
  DoublyList dll;
  dll.push_back(5);
  dll.push_back(6);
  dll.push_front(2);
  dll.push_front(1);
  dll.push_back(3);
  dll.push_back(4);
  dll.display();
  cout<<"size of list:"<<dll.size();
  return 0;
  
}



// CIRCULAR LIST

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
class CircularList{
Node* head;
Node* tail;
public:
CircularList(){
  head = tail = NULL;
}

void push_front(int val){
  Node* newNode = new Node(val);
  if(head==NULL){
    head = tail = newNode;
    tail->next = head;
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
  cout<<temp->data<<endl;
}

int size(){
  Node* temp = head->next;
  int count = 1;
  while(temp!=head){
    count++;
    temp = temp->next;
  }
  return count;
}
};
int main(){
  CircularList cl;
  cl.push_front(5);
  cl.push_front(4);
  cl.push_front(3);
  cl.push_front(2);
  cl.push_front(1);
  cl.display();
  cout<<"size of list is :"<<cl.size();
  return 0;

}
