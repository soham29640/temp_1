#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; 
    return newNode;
}


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode; 
        newNode->next = *head; 
    }
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("List elements: ");
    
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); 
    
    printf("\n");
}


int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &n);

    
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    
    displayList(head);

    return 0;
}
