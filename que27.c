#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}


void append(struct Node** head, int data) {
    struct Node* temp = newNode(data);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct Node* curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
}


struct Node* findNode(struct Node* head, int value) {
    while (head != NULL) {
        if (head->data == value)
            return head;
        head = head->next;
    }
    return NULL;
}


struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    struct Node* p1 = head1;
    struct Node* p2 = head2;

    while (p1 != p2) {
        p1 = (p1 == NULL) ? head2 : p1->next;
        p2 = (p2 == NULL) ? head1 : p2->next;
    }
    return p1;
}

int main() {
    int n, m, x;

    struct Node *head1 = NULL, *head2 = NULL;

    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        append(&head1, x);
    }

    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        append(&head2, x);
    }

    
    struct Node* intersectionNode = findNode(head1, 30);
    if (intersectionNode != NULL) {
        struct Node* temp = head2;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = intersectionNode;
    }

    struct Node* result = getIntersection(head1, head2);

    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}