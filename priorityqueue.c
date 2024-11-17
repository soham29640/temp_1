#include <stdio.h>
#include <stdlib.h>

// Structure for a priority queue node
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the queue is empty
int isEmpty(struct Node* head) {
    return head == NULL;
}

// Function to enqueue an element with a given priority
void enqueue(struct Node** head, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    // If the list is empty or the new node has higher priority than the head
    if (*head == NULL || (*head)->priority > priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        // Traverse the list to find the correct position to insert
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Enqueued element %d with priority %d\n", data, priority);
}

// Function to dequeue the highest priority element (lowest priority value)
void dequeue(struct Node** head) {
    if (isEmpty(*head)) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return;
    }
    struct Node* temp = *head;
    printf("Dequeued element %d with priority %d\n", temp->data, temp->priority);
    *head = (*head)->next;
    free(temp);
}

// Function to traverse and display the priority queue
void traverse(struct Node* head) {
    if (isEmpty(head)) {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Priority Queue elements:\n");
    while (head != NULL) {
        printf("Data: %d, Priority: %d\n", head->data, head->priority);
        head = head->next;
    }
}

// Main function with a menu-driven interface
int main() {
    struct Node* head = NULL;
    int choice, data, priority;

    while (1) {
        printf("\n--- Priority Queue Operations ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Remove)\n");
        printf("3. Traverse (Display)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                printf("Enter priority of the element: ");
                scanf("%d", &priority);
                enqueue(&head, data, priority);
                break;
            case 2:
                dequeue(&head);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
