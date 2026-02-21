#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, i, value;
    struct node *head = NULL, *temp = NULL, *newNode = NULL;

    
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct node *)malloc(sizeof(struct node));
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

    
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}