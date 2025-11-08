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

// INSERT FUNCTION
Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val == root->data) {
        cout << "Duplicate value not allowed!";
        return root;
    }
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (root == NULL) return NULL;
    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

//  MAXIMUM DEPTH
int maxDepth(Node* root) {
    if (root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

//  MINIMUM DEPTH
int minDepth(Node* root) {
    if (root == NULL) return 0;
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// INORDER TRAVERSAL 
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Max Depth = " << maxDepth(root) << endl;
    cout << "Min Depth = " << minDepth(root) << endl;

    root = deleteNode(root, 2);
    cout << "After deleting 2: ";
    inorder(root);
    cout << endl;

    return 0;
}
