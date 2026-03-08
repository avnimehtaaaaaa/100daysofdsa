#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;

    if(front == NULL) {
        front = rear = temp;
        temp->next = front;
    }
    else {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
}

// Dequeue operation
void dequeue() {
    if(front == NULL) {
        return;
    }

    struct Node* temp = front;

    if(front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

// Display queue
void display() {
    if(front == NULL) return;

    struct Node* temp = front;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != front);
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}