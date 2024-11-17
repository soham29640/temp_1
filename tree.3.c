#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Preorder traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Inorder traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to search for an element in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Function to find the minimum value node in the BST
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find the maximum value node in the BST
struct Node* findMax(struct Node* root) {
    while (root && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to delete a node in the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to calculate the height of the tree
int height(struct Node* root) {
    if (root == NULL) return -1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to count the number of leaf nodes
int countLeaves(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

// Main function with menu-driven options
int main() {
    struct Node* root = NULL;
    int choice, data;
    
    while (1) {
        printf("\n\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert an element\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search an element\n");
        printf("6. Delete an element\n");
        printf("7. Find the largest element\n");
        printf("8. Find the smallest element\n");
        printf("9. Height of the tree\n");
        printf("10. Count number of leaf nodes\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &data);
                struct Node* found = search(root, data);
                if (found) {
                    printf("Element %d found.\n", data);
                } else {
                    printf("Element %d not found.\n", data);
                }
                break;
            case 6:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 7:
                if (root) {
                    struct Node* maxNode = findMax(root);
                    printf("Largest element: %d\n", maxNode->data);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 8:
                if (root) {
                    struct Node* minNode = findMin(root);
                    printf("Smallest element: %d\n", minNode->data);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 9:
                printf("Height of the tree: %d\n", height(root));
                break;
            case 10:
                printf("Number of leaf nodes: %d\n", countLeaves(root));
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
