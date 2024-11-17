#include <stdio.h>
#include <stdlib.h>


struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
};


struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}


void insert(struct Node** head, int row, int col, int value) {
    struct Node* newNode = createNode(row, col, value);

    if (*head == NULL) {
        *head = newNode;  
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;  
        }
        temp->next = newNode;  
    }
}


void display(struct Node* head) {
    if (head == NULL) {
        printf("The sparse matrix is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Row\tCol\tValue\n");
    while (temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}


int main() {
    int row, col, value;
    int rows, cols;
    struct Node* head = NULL;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element at [%d][%d]: ", i, j);
            scanf("%d", &value);
            if (value != 0) {
                insert(&head, i, j, value);  
            }
        }
    }

    
    printf("\nSparse Matrix Representation:\n");
    display(head);

    return 0;
}
