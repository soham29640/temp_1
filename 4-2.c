#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (!newNode) return;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of bounds\n");
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}


void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    if (position == 1) {
        *head = temp->next;
        free(temp);
    } else {
        struct Node* prev = NULL;
        for (int i = 1; i < position && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of bounds\n");
        } else {
            prev->next = temp->next;
            free(temp);
        }
    }
}


int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int searchElement(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key)
            return position;
        temp = temp->next;
        position++;
    }
    return -1;  
    
}


void sortList(struct Node** head) {
    if (*head == NULL)
        return;

    struct Node* current = *head;
    struct Node* index = NULL;
    int temp;

    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}


void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}


int main() {
    struct Node* head = NULL;
    int choice, data, position, key, searchResult;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node at specific position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Count nodes\n");
        printf("4. Traverse the list\n");
        printf("5. Search an element in the list\n");
        printf("6. Sort the list in ascending order\n");
        printf("7. Reverse the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 3:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 4:
                traverseList(head);
                break;
            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                searchResult = searchElement(head, key);
                if (searchResult != -1)
                    printf("Element found at position %d\n", searchResult);
                else
                    printf("Element not found in the list\n");
                break;
            case 6:
                sortList(&head);
                printf("List sorted in ascending order.\n");
                traverseList(head);
                break;
            case 7:
                reverseList(&head);
                printf("List reversed.\n");
                traverseList(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
