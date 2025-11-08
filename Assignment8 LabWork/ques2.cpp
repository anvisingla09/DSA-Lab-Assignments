// RECURSIVE APPROACH
#include<iostream>
using namespace std;
struct Node{
public:
int data;
Node* left;
Node* right;
Node(int val){
  data = val;
  left = right = NULL;
}
};
Node* searchRec(Node* root , int key){
  if(root == NULL || root->data == key){
    return root;
  }
  if(key<root->data){
    return searchRec(root->left,key);
  }
  else{
    return searchRec(root->right,key);
  }
  
}
int main(){
  Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
  int key = 9;
  Node* result = searchRec(root,key);
  if(result)
    cout<<"Element " << key << " found in BST"<<endl;
  else
    cout<<"element " << key << " not found in BST"<<endl;
  return 0;
}

// NON RECURSIVE APPROACH
#include<iostream>
using namespace std;
struct Node{
public:
int data;
Node* left;
Node* right;
Node(int val){
  data = val;
  left = right = NULL;
}
};
Node* searchNonRec(Node* root,int key){
  while(root!=NULL){
    if(root->data==key) return root;
    else if(key<root->data) return root = root->left;
    else return root=root->right;
  }
  return NULL;
}
int main(){
  Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
  int key = 2;
  Node* result = searchNonRec(root,key);
  if(result)
    cout<<"Element " << key << " found in BST"<<endl;
  else
    cout<<"element " << key << " not found in BST"<<endl;
  return 0;

}



//  MAX AND MIN ELEMENT
#include<iostream>
using namespace std;
struct Node{
public:
int data;
Node* left;
Node* right;
Node(int val){
  data = val;
  left = right = NULL;
}
};
int findMax(Node* root){
  while(root->right!=NULL){
    root = root->right;
     
  }
  return root->data;
}
int findMin(Node* root){
  while(root->left!=NULL){
    root=root->left;
  }
  return root->data;
}
int main(){
  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(6);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  cout<<"Max element in BST "<<findMax(root)<<endl;
  cout<<"Min element in BST "<<findMin(root)<<endl;
  
}


// INORDER SUCCESSOR AND PREDECESSOR
#include<iostream>
using namespace std;
struct Node{
public:
int data;
Node* left;
Node* right;
Node(int val){
  data = val;
  left = right = NULL;
}
};
Node* inorderSuccessor(Node* root, Node* node) {
  Node* succ = NULL;
  while(root != NULL) {
      if(node->data < root->data) {
          succ = root;
          root = root->left;
      } else root = root->right;
  }
  return succ;
}

Node* inorderPredecessor(Node* root, Node* node) {
  Node* pred = NULL;
  while(root != NULL) {
      if(node->data > root->data) {
          pred = root;
          root = root->right;
      } else root = root->left;
  }
  return pred;
}
int main(){
  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(6);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  Node* node = root->left;
    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);

    if (succ != NULL)
        cout << "Inorder Successor is: " << succ->data << endl;
    else
        cout << "Inorder Successor does not exist" << endl;

    if (pred != NULL)
        cout << "Inorder Predecessor is: " << pred->data << endl;
    else
        cout << "Inorder Predecessor does not exist" << endl;
return 0;
}



