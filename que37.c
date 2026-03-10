#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

void push_front(int value)
{
    if(front == 0)
    {
        printf("Deque Overflow\n");
    }
    else if(front == -1)
    {
        front = rear = 0;
        deque[front] = value;
    }
    else
    {
        front--;
        deque[front] = value;
    }
}

void push_back(int value)
{
    if(rear == MAX-1)
    {
        printf("Deque Overflow\n");
    }
    else if(front == -1)
    {
        front = rear = 0;
        deque[rear] = value;
    }
    else
    {
        rear++;
        deque[rear] = value;
    }
}

void pop_front()
{
    if(front == -1)
    {
        printf("Deque Underflow\n");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void pop_back()
{
    if(front == -1)
    {
        printf("Deque Underflow\n");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear--;
    }
}

void show_front()
{
    if(front == -1)
        printf("Deque Empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

void show_back()
{
    if(front == -1)
        printf("Deque Empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

void size()
{
    if(front == -1)
        printf("Size: 0\n");
    else
        printf("Size: %d\n", rear - front + 1);
}

void empty()
{
    if(front == -1)
        printf("Deque is Empty\n");
    else
        printf("Deque is Not Empty\n");
}

void display()
{
    if(front == -1)
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque elements: ");
    for(int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);

    display();

    show_front();
    show_back();

    pop_front();
    display();

    pop_back();
    display();

    size();
    empty();

    return 0;
}