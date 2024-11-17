#include <stdio.h>
#include <stdlib.h>

// Define a structure for tree nodes
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Define a structure for stack nodes
struct Stack {
    struct Node *node;
    struct Stack *next;
};

// Function to create a new tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a stack node
struct Stack* createStackNode(struct Node *node) {
    struct Stack* stackNode = (struct Stack*)malloc(sizeof(struct Stack));
    stackNode->node = node;
    stackNode->next = NULL;
    return stackNode;
}

// Function to push a node onto the stack
void push(struct Stack **stack, struct Node *node) {
    struct Stack *stackNode = createStackNode(node);
    stackNode->next = *stack;
    *stack = stackNode;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack == NULL;
}

// Function to pop a node from the stack
struct Node* pop(struct Stack **stack) {
    if (isEmpty(*stack)) return NULL;
    struct Stack *temp = *stack;
    *stack = (*stack)->next;
    struct Node *node = temp->node;
    free(temp);
    return node;
}

// Non-Recursive Inorder Traversal
void inorderTraversal(struct Node *root) {
    struct Stack *stack = NULL;
    struct Node *current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

// Non-Recursive Preorder Traversal
void preorderTraversal(struct Node *root) {
    if (root == NULL) return;

    struct Stack *stack = NULL;
    push(&stack, root);

    while (!isEmpty(stack)) {
        struct Node *current = pop(&stack);
        printf("%d ", current->data);

        // Push right child first so that left child is processed first
        if (current->right != NULL) push(&stack, current->right);
        if (current->left != NULL) push(&stack, current->left);
    }
}

// Non-Recursive Postorder Traversal
void postorderTraversal(struct Node *root) {
    if (root == NULL) return;

    struct Stack *stack1 = NULL, *stack2 = NULL;
    push(&stack1, root);

    while (!isEmpty(stack1)) {
        struct Node *current = pop(&stack1);
        push(&stack2, current);

        if (current->left != NULL) push(&stack1, current->left);
        if (current->right != NULL) push(&stack1, current->right);
    }

    while (!isEmpty(stack2)) {
        printf("%d ", pop(&stack2)->data);
    }
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
