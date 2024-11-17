#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void append(struct Node** head, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head;
    if (*head == NULL) {
        *head=new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to merge lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;
    
    while (list1 != NULL) {
        // Even numbers from list1
        if (list1->data % 2 == 0) {
            append(&mergedList, list1->data);
        }
        list1 = list1->next;
    }
    
    while (list2 != NULL) {
        // Odd numbers from list2
        if (list2->data % 2 != 0) {
            append(&mergedList, list2->data);
        }
        list2 = list2->next;
    }
    
    return mergedList;
}
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n1, n2, data;
    // Input for List1
    printf("Enter the number of elements in List1: ");
    scanf("%d", &n1);
    printf("Enter the elements of List1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data);
        append(&list1, data);
    }
    // Input for List2
    printf("Enter the number of elements in List2: ");
    scanf("%d", &n2);
    printf("Enter the elements of List2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data);
        append(&list2, data);
    }
    printf("List1: ");
    displayList(list1);
    printf("List2: ");
    displayList(list2);
    
    // Merging the lists
    struct Node* mergedList = mergeLists(list1, list2);
    printf("Merged List: ");
    displayList(mergedList);
    return 0;
}