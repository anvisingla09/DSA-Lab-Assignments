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
  head = tail=NULL;
}

void push_front(int val){
  Node* newNode = new Node(val);
  if(head==NULL){
    head = tail = newNode;
    return;
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

int counting(int key){
  Node* temp = head;
  int count = 0;
  while(temp!=NULL){
    if(temp->data == key){
      count++;
    }
    temp=temp->next;
  }
  return count;
}

void deleteKey(int key) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->data == key) {
        head = temp->next;
        delete temp;
        temp = head;
    }

    while (temp != NULL) {
        if (temp->data == key) {
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}


};
int main(){
  List ll;
  ll.push_front(1);
  ll.push_front(3);
  ll.push_front(1);
  ll.push_front(2);
  ll.push_front(1);
  ll.push_front(2);
  ll.push_front(1);
  ll.printList();
  cout<<ll.counting(1)<<endl;
  ll.deleteKey(1);
  ll.printList();
}
