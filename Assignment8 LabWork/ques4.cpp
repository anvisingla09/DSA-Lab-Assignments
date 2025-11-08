#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool isBSTUtil(Node* root, Node* minNode, Node* maxNode) {
    if (root == NULL) return true;

    if ((minNode && root->data <= minNode->data) || 
        (maxNode && root->data >= maxNode->data))
        return false;

    return isBSTUtil(root->left, minNode, root) && 
           isBSTUtil(root->right, root, maxNode);
}

bool isBST(Node* root) {
    return isBSTUtil(root, NULL, NULL);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    if (isBST(root))
        cout << "This is a BST\n";
    else
        cout << "This is NOT a BST\n";

    return 0;
}
