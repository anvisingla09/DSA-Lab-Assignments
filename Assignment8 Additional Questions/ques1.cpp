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
class Solution {
public:
    int sumOfLeftLeaves(Node* root) {
        if(!root) return 0;
        int sum = 0;

        if(root->left) {
            if(!root->left->left && !root->left->right)
                sum += root->left->data;
            else
                sum += sumOfLeftLeaves(root->left);
        }
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};
int main(){
  Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
  Solution s;
  cout<<"sum is :"<<s.sumOfLeftLeaves(root);
  return 0;
}

