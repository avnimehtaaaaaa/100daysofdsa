#include <stdio.h>
#include <stdlib.h>

// Definition of node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to rotate linked list right by k
void rotateRight(struct Node** head, int k) {
    if (*head == NULL || k == 0)
        return;

    struct Node* temp = *head;
    int count = 1;

    // Find length and last node
    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    // Make list circular
    temp->next = *head;

    // Effective rotations
    k = k % count;
    int steps = count - k;

    // Move to (n-k)th node
    struct Node* newTail = *head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Set new head and break circular link
    *head = newTail->next;
    newTail->next = NULL;
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, k, value;

    // Input number of nodes
    scanf("%d", &n);

    // Input list elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    // Input k
    scanf("%d", &k);

    // Rotate list
    rotateRight(&head, k);

    // Output rotated list
    printList(head);

    return 0;
}