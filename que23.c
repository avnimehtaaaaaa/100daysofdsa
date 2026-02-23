#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node *head = NULL, *tail = NULL;

    while (l1 != NULL && l2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        if (l1->data <= l2->data) {
            newNode->data = l1->data;
            l1 = l1->next;
        } else {
            newNode->data = l2->data;
            l2 = l2->next;
        }
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    while (l1 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = l1->data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        l1 = l1->next;
    }

    while (l2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = l2->data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        l2 = l2->next;
    }

    return head;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, m;
    struct Node *list1, *list2, *merged;

    scanf("%d", &n);
    list1 = createList(n);

    scanf("%d", &m);
    list2 = createList(m);

    merged = mergeLists(list1, list2);

    display(merged);

    return 0;
}