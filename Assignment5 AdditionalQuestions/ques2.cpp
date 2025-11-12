#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int val){
  data = val;
  next=NULL;
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
    head = tail = newNode;
  }
  else{
    newNode->next = head;
    head = newNode;
  }
}

void printList(){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
}

Node* reverse(Node* head, int k){
  Node* temp = head;
  int count = 0;
  while(count<k){
    if(temp==NULL){
      return head;
    }
    temp=temp->next;
    count++;
  }

 Node*  prevNode = reverse(temp,k);
temp = head;
  int ct = 0;
  while(ct<k){
  Node* next = temp->next;
  temp->next = prevNode;
  prevNode = temp;
  temp = next;
  ct++;
  }
  return prevNode;
  }

};
int main(){
  List list1;
  list1.push_front(5);
  list1.push_front(4);
  list1.push_front(3);
  list1.push_front(2);
  list1.push_front(1);
  list1.printList();
  list1.head=list1.reverse(list1.head,3);
  list1.printList();  
}
