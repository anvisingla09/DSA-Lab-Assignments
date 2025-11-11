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
Node* head;
Node* tail;
public:
List(){
  head=tail=NULL;
}

void push_front(int val){
  Node* newNode = new Node(val);
  if(head==NULL){
    head=tail=newNode;
  }
  else{
    newNode->next=head;
    head = newNode;
  }
}

Node* gethead(){
  return head;
}

void printList(){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
  return;
}

int length(Node* head){
  int len=0;
  while(head!=NULL){
    len++;
    head=head->next;
  }
  return len;
}

Node* intersection(Node* head1, Node* head2){
  int l1 = length(head1);
  int l2 = length(head2);
  int d=0;
  Node* ptr1;
  Node* ptr2;
  if(l1>l2){
    d = abs(l1-l2);
    ptr1 = head1;
    ptr2 = head2;
  }
  else{
    d = abs(l2-l1);
    ptr1 = head2;
    ptr2 = head1;
  }
  while(d!=0){
    ptr1=ptr1->next;
    if(ptr1==NULL) return NULL;
    d--;
  }
  while(ptr1!=NULL && ptr2!=NULL){
    if(ptr1==ptr2) return ptr1;
    ptr1=ptr1->next;
    ptr2=ptr2->next;
  }
  return NULL;
}
};

int main(){
  Node* common = new Node(8);
  common->next = new Node(5);

  List list1;
  list1.push_front(1);
  list1.push_front(4);
  list1.gethead()->next->next = common;

  List list2;
  list2.push_front(1);
  list2.push_front(6);
  list2.push_front(5);
  list2.gethead()->next->next->next = common;

  list1.printList();
  list2.printList();

  Node* intersection = list2.intersection(list1.gethead(), list2.gethead());
  if (intersection!= NULL)
      cout << "Intersected at node with value: " << intersection->data << endl;
  else
      cout << " No intersection found." << endl;
}
