#include <stdio.h>
#include <stdlib.h>

// Define a structure for tree nodes
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;

    inorderTraversal(root->left);          // Visit left subtree
    printf("%d ", root->data);             // Visit root node
    inorderTraversal(root->right);         // Visit right subtree
}

// Preorder Traversal (Root, Left, Right)
void preorderTraversal(struct Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);             // Visit root node
    preorderTraversal(root->left);         // Visit left subtree
    preorderTraversal(root->right);        // Visit right subtree
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(struct Node* root) {
    if (root == NULL) return;

    postorderTraversal(root->left);        // Visit left subtree
    postorderTraversal(root->right);       // Visit right subtree
    printf("%d ", root->data);             // Visit root node
}

// Main function to demonstrate tree traversal
int main() {
    // Creating the following binary tree
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
